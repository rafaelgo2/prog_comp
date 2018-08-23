#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

#define MAXV 100010

typedef vector<int> vi;

vi g[MAXV];
int visited[MAXV];

int dfs(int v){
	if (visited[v]) return 0;
	visited[v] = true;
	int ans = 1;
	for (int w : g[v])
		ans += dfs(w);
	return ans;
}

int main(){ _
	int n, m, v;
	string s;
	while (true){
		cin >> n;
		if (n == 0) break;
		for (int i = 1; i <= n; i++)
			g[i].resize(0);
		while (true){
			cin >> m;
			if (m == 0) break;
			getline(cin, s);
			stringstream sin(s);
			while (sin >> v){
				g[m].push_back(v);
				g[v].push_back(m);
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++){
			memset(visited, 0, sizeof visited);
			visited[i] = true;
			ans += (dfs(i != n ? i+1 : 1) != (n-1));
		}
		cout << ans << endl;
	}
	return 0;
}

