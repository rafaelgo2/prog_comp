#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

#define INF 1e5
#define EPS (1e-5)

typedef double type;

typedef pair<type, type> point;
const point infPoint(INF, INF);
typedef pair<type, type> vec;

#define x first
#define y second

struct segment{
	point A, B;
	segment(point A, point B):
		A(A), B(B){}
};

point operator*(type alpha, point p){
	return point(alpha*p.x, alpha*p.y);
}

point operator+(point l, point r){
	return point(l.x + r.x, l.y + r.y);
}

vec operator-(point l, point r){ //might be confusing
	return vec(l.x - r.x, l.y - r.y);
}

type dot(vec p, vec q){
	return p.x*q.x + p.y*q.y;
}

type cross(vec p, vec q){
	return p.x*q.y - p.y*q.x;
}

type operator*(vec p, vec q){
	return dot(p, q);
}

type operator^(vec p, vec q){
	return cross(p, q);
}

type operator~(vec v){
	return hypot(v.x, v.y);
}

vec operator!(vec v){
	return (1.0/~v)*v;
}


bool intersect_colinear(segment s, point p){
	type minX = min(s.A.x, s.B.x);
	type maxX = max(s.A.x, s.B.x);
	type minY = min(s.A.y, s.B.y);
	type maxY = max(s.A.y, s.B.y);
	return (minX <= p.x) && (p.x <= maxX) && (minY <= p.y) && (p.y <= maxY);
}

int orientation(point p, point q, point r) {
	vec v = q-p;
	vec w = r-q;
	type val = w^v;
    if (-EPS <= val && val <= EPS) return 0;
    return (val > 0)? 1: 2;
}

bool intersect(segment l, segment r){
	int o[4] = {
		orientation(l.A, l.B, r.A),
		orientation(l.A, l.B, r.B),
		orientation(r.A, r.B, l.A),
		orientation(r.A, r.B, l.B)
	};
	if ((o[0] != o[1]) && (o[2] != o[3])) return true;

	if (!o[0] && intersect_colinear(segment(l.A, l.B), r.A)) return true;

	if (!o[1] && intersect_colinear(segment(l.A, l.B), r.B)) return true;

	if (!o[2] && intersect_colinear(segment(r.A, r.B), l.A)) return true;

	if (!o[3] && intersect_colinear(segment(r.A, r.B), l.B)) return true;

	return false;
}

ostream &operator<<(ostream &out, segment &s){
	out << s.A.x << "~" << s.A.y << " -> "
		<< s.B.x << "~" << s.B.y << endl;
	return out;
}

point intersection(segment l, segment r){
	vec v = l.B - l.A;
	vec w = r.B - r.A;
	vec u = r.A - l.A;
	double t = (u^w)/(v^w);
	point ans = l.A + t*v;
	return ans;
}

void convex_hull(vector<point> &v, vector<point> &ans){
	if (v.size() < 3){
		ans = v;
		if (ans.front() != ans.back()) ans.push_back(ans.front());
		return;
	}
	sort(v.begin(), v.end());
	static vector<point> cap;
	cap.resize(0);
	cap.push_back(v[0]), cap.push_back(v[1]);
	for (int i = 2; i < v.size(); i++){
		while(cap.size() >= 2){
			int n = cap.size();
			if (((v[i] - cap[n-2])^(cap[n-1] - cap[n-2])) <= 0)
				cap.pop_back();
			else
				break;
		}
		cap.push_back(v[i]);
	}
	static vector<point> cup;
	cup.resize(0);
	cup.push_back(v[0]), cup.push_back(v[1]);
	for (int i = 2; i < v.size(); i++){
		while(cup.size() >= 2){
			int n = cup.size();
			if (((v[i] - cup[n-2])^(cup[n-1] - cup[n-2])) >= 0)
				cup.pop_back();
			else
				break;
		}
		cup.push_back(v[i]);
	}

	ans.resize(0);
	for (int i = 0; i < cap.size(); i++)
		ans.push_back(cap[i]);
	for (int i = cup.size() - 2; i >= 0; i--)
		ans.push_back(cup[i]);

}

double area(vector<point> &p){
	double ans = 0;
	for (int i = 0; i < p.size()-1; i++)
		ans += p[i]^p[i+1];
	return 0.5*fabs(ans);
}

int main(){ _
	int n, w, h, x, y;
	int t = 1;
	cout << fixed << setprecision(3);
	while (cin >> n >> w >> h >> x >> y){
		point g(x, y);
		cout << "Case #" << t++ << ": ";
		int x1, y1, x2, y2;
		vector<point> cv;
		cv.push_back(point(0, 0));
		cv.push_back(point(0, h));
		cv.push_back(point(w, h));
		cv.push_back(point(w, 0));
		convex_hull(cv, cv);
		for (int i = 0; i < n; i++){
			cin >> x1 >> y1 >> x2 >> y2;
			segment s(point(x1, y1), point(x2, y2));
			bool flag = false;
			vector<point> aux;
			for (int i = 0; i < cv.size() - 1; i++){
				segment l(cv[i], cv[i+1]);
				if (intersect(l, s)){
					flag = true;
					aux.push_back(intersection(l, s));
				}
			}
			for (point p : aux)
				cv.push_back(p);

			aux.resize(0);
			if (!flag) continue;
			int o = orientation(s.A, s.B, g);
			for (point p: cv){
				int o_ = orientation(s.A, s.B, p);
				if (o_ == 0 || o_ == o)
					aux.push_back(p);
			}
			convex_hull(aux, cv);
		}

		cout << area(cv) << endl;
	}
	return 0;
}



