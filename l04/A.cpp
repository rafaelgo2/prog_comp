#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int x[260], y[260], s, b;

bool f[260][260][260];
int memo[260][260][260];

const int INF = 0x3f3f3f3f;

int get(int i, int j, int m){
	if (j == b) return 0;
	int u = (i+0)%s;
	int v = (i+1)%s;
	int w = (i+2)%s;
	if (u == m || v == m) return INF;
	if (!f[i][j][m+1]){
		f[i][j][m+1] = true;
		memo[i][j][m+1] = INF;
		int ans = get(v, j, m);
		ans = min(ans, (x[u]+x[v])*y[j] + get(w, j+1, (m == -1)?u:m));
		memo[i][j][m+1] = ans;
		//cout << i << " " << j << " " << m << " " << ans << endl;
	}
	return memo[i][j][m+1];
}

int main(){ _
	while (true){
		cin >> s >> b;
		if (s + b == 0) break;
		for (int i = 0; i < s; i++)
			cin >> x[i];
		for (int i = 0; i < b; i++)
			cin >> y[i];
		memset(f, 0, sizeof f);
		cout << -get(0, 0, -1) << endl;
	}
	return 0;
}
