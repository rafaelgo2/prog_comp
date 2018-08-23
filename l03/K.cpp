#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

#define INF 1e9
#define EPS 0

typedef double type;

typedef pair<type, type> point;
const point infPoint(INF, INF);
typedef pair<type, type> vec;

#define x first
#define y second

double dist(point l, point r){
	return hypot(l.x - r.x, l.y - r.y);
}

struct segment{
	point A, B;
	segment(point A, point B):
		A(A), B(B){}
	segment(){}
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
    if (val == 0) return 0; 
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

segment p[1010];

typedef pair<double, pair<int, int>> edge;

edge e[1010*1010];


double dist(segment l, point p){
	vec v = l.B-l.A;
	vec w = p - l.A;
	vec v_ = (1.0/~v)*v;
	vec proj = (w*v_)*v_;
	type t = proj*v_;
	if (0 <= t && t <= ~v){
		vec orth = w - proj;
		return ~orth;
	}
	return min(
		dist(l.A, p),
		dist(l.B, p)
	);
}

double dist(segment l, segment r){
	if (intersect(l, r)) return 0.0;
	return min(
		min(
			dist(r, l.A),
			dist(r, l.B)
		),
		min(
			dist(l, r.A),
			dist(l, r.B)
		)
	);
}

#define MAX_ITEMS 10000
struct union_find{
	int id[MAX_ITEMS];
	void init(int n){
		for (int i = 0; i <= n; i++)
			id[i] = i;
	}
	int get_id(int i){
		if (id[i] == i)	return i;
		return id[i] = get_id(id[i]);
	}
	void join(int l, int r){
		int id_l = get_id(l);
		int id_r = get_id(r);
		id[id_l] = id_r;
	}
};

int main(){ _
	int n;
	union_find uf;
	cout << fixed << setprecision(2);
	while (true){
		cin >> n;
		if (n == 0) break;
		int x, y, l;
		for (int i = 0; i < n; i++){
			cin >> x >> y >> l;
			if (l > 0)
				p[i] = segment(point(x, y), point(x+l, y));
			else
				p[i] = segment(point(x, y), point(x, y-l));
		}
		int k = 0;
		for (int i = 0; i < n; i++){
			for (int j = i+1; j < n; j++){
				e[k].first = dist(p[i], p[j]);
				//cout << i << " " << j << " " << e[k].first << endl;
				auto &it = e[k].second;
				it.first = i;
				it.second = j;
				k++;
				//cout << "WTF " << k << endl;
			}
		}
		sort(&e[0], &e[k]);
		uf.init(n+1);
		double ans = 0;
		for (int i = 0; i < k; i++){
			if (uf.get_id(0) == uf.get_id(1)) break;
			//cout << uf.get_id(0) << " " << uf.get_id(1) << endl;
			//cout << e[i].first << endl;
			auto it = e[i].second;
			if (uf.get_id(it.first) == uf.get_id(it.second))
				continue;
			ans = max(ans, e[i].first);
			uf.join(it.first, it.second);
		}
		cout << ans << endl;
	}

	return 0;
}


