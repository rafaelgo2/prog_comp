#include <iostream>
#include <cmath>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

#define INF 1e9
#define EPS 0

typedef long long type;

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
	return v*v;
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

int main(){ _
	int n;
	cin >> n;
	while (n--){
		int xstart, ystart, xend, yend, xleft, ytop, xright, ybottom;
		cin >> xstart >> ystart >> xend >> yend >> xleft >> ytop >> xright >> ybottom;

		if (xright < xleft) swap(xright, xleft);
		if (ytop < ybottom) swap(ytop, ybottom);
		point start(xstart, ystart);
		point end(xend, yend);
		segment line(start, end);
		point left_bottom(xleft, ybottom);
		point left_top(xleft, ytop);
		point right_bottom(xright, ybottom);
		point right_top(xright, ytop);

		segment left(left_bottom, left_top);
		segment top(left_top, right_top);
		segment right(right_top, right_bottom);
		segment bottom(right_bottom, left_bottom);

		bool ans = false;

		if (xleft <= xstart && xstart <= xright)
			if (ybottom <= ystart && ystart <= ytop)
				ans = true;

//	if (ans){
//		cout << "LEFT INSIDE!" << endl;
//		continue;
//	}

		if (xleft <= xend && xend <= xright)
			if (ybottom <= yend && yend <= ytop)
				ans = true;

//	if (ans){
//		cout << "RIGHT INSIDE!" << endl;
//		continue;
//	}

		if (intersect(left, line)) ans = true;
//	if (ans){
//		cout << "INTERSECT LEFT" << endl;
//		continue;
//	}

		if (intersect(top, line)) ans = true;
//	if (ans){
//		cout << "INTERSECT TOP" << endl;
//		continue;
//	}

		if (intersect(right, line)) ans = true;
//	if (ans){
//		cout << "INTERSECT RIGHT" << endl;
//		continue;
//	}

//	cout << line.A.x << " " << line.A.y << endl;
//	cout << line.B.x << " " << line.B.y << endl;


//	cout << bottom.A.x << " " << bottom.A.y << endl;
//	cout << bottom.B.x << " " << bottom.B.y << endl;
		if (intersect(bottom, line)) ans = true;
//	if (ans){
//		cout << "INTERSECT BOTTOM" << endl;
//		continue;
//	}
		if (ans) cout << "T" << endl;
		else cout << "F" << endl;
	}
	return 0;
}

