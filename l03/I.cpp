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

int orientation(vec v, vec w){
	type t = w^v;
	if (t > 0) return 1;
	if (t < 0) return -1;
	return 0;
}


point b[110];
point w[110];

int main(){ _
	int n, m;
	while (cin >> n >> m){
		for (int i = 0; i < n; i++)
			cin >> b[i].x >> b[i].y;

		for (int i = 0; i < m; i++)
			cin >> w[i].x >> w[i].y;

		int ans = 0;
		for (int i = 0; i < n; i++){
			for (int j = i+1; j < n; j++){
				for (int k = j+1; k < n; k++){
					vec t = b[j] - b[i];
					vec u = b[k] - b[j];
					vec v = b[i] - b[k];
					int sum = 0;
					for (int l = 0; l < m; l++){
						type alpha = orientation(t, w[l] - b[i]);
						type beta = orientation(u, w[l] - b[j]);
						type gamma = orientation(v, w[l] - b[k]);
						//cout << alpha << beta << gamma << endl;
						sum += (alpha == beta && beta == gamma);
					}
					ans += sum*sum;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}




