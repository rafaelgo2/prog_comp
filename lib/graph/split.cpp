//https://en.m.wikipedia.org/wiki/Split_graph

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

typedef vector<int> vi;

int main(){ _
	int n, m;
	int d[50010];
	while (true){
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		int u, v;
		memset(d, 0, sizeof d);
		for (int i = 0; i < m; i++){
			cin >> u >> v;
			d[u]++;
			d[v]++;
		}
		sort(d+1, d+1+n, greater<int>());
		int m = 1;
		while (m+1 <= n && d[m+1] >= m) m++;
		int l = 0;
		for (int i = 0; i <= m; i++) l += d[i];
		int r = m*(m-1);
		for (int i = m+1; i <= n; i++) r += d[i];
		if (l == r) cout << "Y" << endl;
		else cout << "N" << endl;
	}

	return 0;
}
