#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

typedef long long int type;

typedef pair<type, type> point;
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

type operator~(vec v){
	return v.x*v.x + v.y*v.y;
}

type d[2][1100];

const type PI = 3141;

int main(){ _
	int n;
	int s = 1;
	vector<type> dist;
	while (true){
		cin >> n;
		if (n == 0) break;
		double x1, y1, x2, y2, x_, y_, t;
		cin >> x1 >> y1 >> x2 >> y2 >> t;
		point c[2] = {point(1000*x1, 1000*y1), point(1000*x2, 1000*y2)};
		type T = type(1000*1000)*type(1000*t);
		dist.resize(0);
		for (int i = 0; i < n; i++){
			cin >> x_ >> y_;
			point p(1000*x_, 1000*y_);
			d[0][i] = ~(p-c[0])*PI;
			dist.push_back(d[0][i]);
			d[1][i] = ~(p-c[1])*PI;
			dist.push_back(d[1][i]);
		}

		int ans = 0;
		for (type L : dist){
			if (L > T) continue;
			type R = T - L;
			int tmp = 0;
			for (int i = 0; i < n; i++){
				if (d[0][i] <= L) tmp++;
				else if (d[1][i] <= R) tmp++;
			}
			ans = max(tmp, ans);

			tmp = 0;
			for (int i = 0; i < n; i++){
				if (d[0][i] <= R) tmp++;
				else if (d[1][i] <= L) tmp++;
			}
			ans = max(tmp, ans);
		}
		cout << s++ << ". " << n-ans << endl;
	}
	return 0;
}





