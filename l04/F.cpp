#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int n;
vector<double> x;
vector<double> y;

double dist(int l, int r){
	return hypot(x[l]-x[r], y[l]-y[r]);
}

vector<vector<double>> memo;

double get(int l, int r){
	int v = 1+max(l, r);
	if (v == n-1)
		return dist(l, v) + dist(v, r);
	if (fabs(memo[l][r]+1) < 1e-7){
		memo[l][r] = min(
			dist(l, v) + get(v, r),
			dist(v, r) + get(l, v)
		);
	}
	return memo[l][r];
}

int main(){ _
	cout << fixed << setprecision(2);
	while (cin >> n){
		x.resize(n);
		y.resize(n);
		memo.resize(n);
		for (int i = 0; i < n; i++)
			memo[i] = vector<double>(n, -1);
		for (int i = 0; i < n; i++)
			cin >> x[i] >> y[i];
		
		cout << get(0, 0) << endl;
	}
	return 0;
}

