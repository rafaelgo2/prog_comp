#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

#define INF 1e9
#define EPS 0

typedef int type;

typedef pair<type, type> point;
const point infPoint(INF, INF);
typedef pair<type, type> vec;

#define x first
#define y second

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

struct line{
	point A;
	point B;
	vec dir;
	line(point A, point B):
		A(A), B(B){}
};

point p[1010];

bool intersect(line l, point p){
	vec v = l.A - p;
	vec w = l.B - p;
	return (v^w) == 0;
}

int main(){ _
	int m;
	scanf("%d", &m);
	while (m--){
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d%d", &p[i].x, &p[i].y);

		int ans = 0;
		for (int i = 0; i < n; i++){
			for (int j = i+1; j < n; j++){
				int sum = 0;
				line l(p[i], p[j]);
				for (int k = j+1; k < n; k++)
					sum += intersect(l, p[k]);
				ans = max(ans, sum + 2);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}


