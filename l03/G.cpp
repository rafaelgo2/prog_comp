#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

#define INF 1e9
#define EPS 0

typedef long long int type;

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

point p[310];
bool flag[310][310];

bool intersect(line l, point p){
	vec v = p - l.A;
	vec w = l.B - l.A;
	return (v^w) == 0;
}

int main(){ _
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> p[i].x >> p[i].y;

	memset(flag, 0, sizeof flag);
	long double ans = 0;

	vector<int> v;
	for (int i = 0; i < n; i++){
		for (int j = i+1; j < n; j++){
			if (flag[i][j]) continue;
			line l(p[i], p[j]);
			v.resize(0);
			v.push_back(i);
			v.push_back(j);
			for (int k = j+1; k < n; k++){
				if (intersect(l, p[k]))
					v.push_back(k);
			}
			for (int l : v)
				for (int r : v)
					flag[l][r] = 1;


			point minP = p[v.front()];
			point maxP = p[v.front()];
			for (int l : v){
				minP = min(minP, p[l]);
				maxP = max(maxP, p[l]);
			}
			ans += hypot(minP.x - maxP.x, minP.y - maxP.y);
		}
	}
	cout << type(round(ans)) << endl;
	return 0;
}



