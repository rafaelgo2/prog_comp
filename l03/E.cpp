#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

#define INF 1e9
#define EPS 1e-4

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

point p[10010];

int main(){ _
	int n;
	cout << fixed << setprecision(4);
	while (true){
		cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; i++)
			cin >> p[i].x >> p[i].y;

		double ans = 10000*10000;
		for (int i = 0; i < n; i++)
			for (int j = i+1; j < n; j++){
				vec v = p[i]-p[j];
				ans = min(ans, v*v);
			}
		ans = sqrt(ans);
		if (ans >= 10000) cout << "INFINITY" << endl;
		else cout << ans << endl;
	}
	return 0;
}
