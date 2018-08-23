#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

#define INF 1e9
#define EPS 1e-4

typedef int type;

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

struct line{
	double a, b, c;
	point A, B;
	line(segment s){
		A = s.A, B = s.B;
		if (fabs(A.x - B.x) < EPS){ //vertical line
			a = 1, b = 0, c = -A.x;
			return;
		}
		a = (A.y - B.y)/(A.x - B.x);
		b = 1;
		c = -(a*A.x) - A.y;
	}
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

double length(vec v){
	return hypot(v.x, v.y);
}

type cross(vec p, vec q){
	return p.x*q.y - p.y*q.x;
}
//if (l < 0)
//	cout << "RIGHT" << endl;
//else if (l > 0)
//	cout << "LEFT" << endl;
//else
//	cout << "TOWARDS" << endl;


//aula unicamp
type operator*(vec p, vec q){
	return dot(p, q);
}

type operator^(vec p, vec q){
	return cross(p, q);
}

double operator~(vec v){
	return length(v);
}

double dist(point P, line l){//ou fabs se type double
	return 1.0*abs(l.a*P.x + l.b*P.y + l.c)/hypot(l.a, l.b);
}

point nearestPoint(point P, line l){
	vec AP = P - l.A, AB = l.B - l.A;
	double alpha = 1.0 *dot(AP, AB) / dot(AB, AB);
	return l.A + alpha*AB;
}

point nearestPoint(point P, segment s){
	if (((P - s.A)*(s.B - s.A) >= 0) &&
		((P - s.B)*(s.A - s.B) >= 0)
	){//inside segment
		return nearestPoint(P, line(s));
	}
	else{
		if (~(P - s.A) < ~(P - s.B))
			return s.A;
		else
			return s.B;
	}
/*	vec AP = P - s.A, AB = s.B - s.A;
	double alpha = dot(AP, AB) / dot(AB, AB);
	if (alpha < 0.0)
		return s.A;
	if (alpha > 1.0)
		return s.B;
	return nearestPoint(P, line(s));
*/
}

bool intersect(segment l, segment r){
	return false;
}

point operator^(segment l, segment r){
	return infPoint;
}

vec norm(line l){//normal vector
	return point(l.a, l.b);
}

bool intersect(line l, line r){
	return ((fabs(norm(l)^norm(r)) < EPS) && true); //colinear
}

point operator^(line l, line r){ //type double
	double den = norm(l)^norm(r);
	//Cramer's rule
	return point(
		(-l.c*r.b + l.b*r.c)/den,
		(-l.c*r.a + l.a*r.c)/den
	);
}

struct circle{
	point c;
	type r;
};

void convex_hull(vector<point> &in, vector<point> &ans){
	if (in.size() < 3){
		ans = in;
		if (ans.front() != ans.back()) ans.push_back(ans.front());
		return;
	}

	vector<point> v(in);
	sort(v.begin(), v.end());
	static vector<point> cap;
	cap.resize(0);
	cap.push_back(v[0]), cap.push_back(v[1]);
	for (int i = 2; i < v.size(); i++){
		while(cap.size() >= 2){
			int n = cap.size();
			if (((v[i] - cap[n-2])^(cap[n-1] - cap[n-2])) <= 0) // <= exclude colinear points
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
			if (((v[i] - cup[n-2])^(cup[n-1] - cup[n-2])) >= 0) //>= exclude colinear points
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
	return fabs(ans);
}

int main(){ _
	int n;
	cout << fixed << setprecision(2);
	int t = 1;
	while (true){
		cin >> n;
		if (n == 0) break;
		vector<point> p(n);
		for (int i = 0; i < n; i++)
			cin >> p[i].x >> p[i].y;
		vector<point> cv;
		convex_hull(p, cv);
		p.push_back(p[0]);
		double l = area(p);
		double r = area(cv);
		cout << "Tile #" << t++ << endl;
		cout << "Wasted Space = ";
		cout << 100*(r-l)/r;
		cout << " %" << endl;
		cout << endl;
	}
	return 0;
}


