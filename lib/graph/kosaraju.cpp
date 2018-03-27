#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

typedef vector<int> vi;

int dfs(int v, vector<int> &ord, vi g[2010], bool visited[2010]){
	if (visited[v]) return 0;
	int ans = 1;
	visited[v] = true;
	for (int w : g[v])
		ans += dfs(w, ord, g, visited);
	ord.push_back(v);
	return ans;
}

int main(){ _
	int n, m;
	vi g[2][2010];
	vector<int> ord;
	bool visited[2010];
	while (true){
		cin >> n >> m;
		if (n+m == 0) break;
		g[1][0].resize(0);
		for (int i = 1; i <= n; i++){
			g[0][i].resize(0);
			g[1][i].resize(0);
			visited[i] = false;
			g[1][0].push_back(i);
		}
		int v, w, c;
		for (int i = 0; i < m; i++){
			cin >> v >> w >> c;
			g[0][v].push_back(w);
			g[1][w].push_back(v);
			if (c == 2){
				g[1][v].push_back(w);
				g[0][w].push_back(v);
			}
		}
		ord.resize(0);
		memset(visited, false, sizeof visited);
		dfs(0, ord, g[1], visited);
		ord.pop_back();
		int root = ord.back();
		ord.resize(0);
		memset(visited, false, sizeof visited);
		cout << (dfs(root, ord, g[0], visited) == n) << endl;
	}
	return 0;
}
