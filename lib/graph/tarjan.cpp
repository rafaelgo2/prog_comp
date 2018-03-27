#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

typedef vector<int> vi;
#define MAX 9999

int color[MAX];
int parent[MAX];
int disc[MAX];
vi graph[MAX];
vector<int> s;

void t_dfs(int v, int &d){
	parent[v] = ++d;
	s.push_back(v);
	color[v] = 1;
	int d_ = parent[v];
	for (int w : graph[v]){
		if (color[w] == 2) continue;
		if (color[w] == 0) t_dfs(w, d);
		parent[v] = min(parent[v], parent[w]);
	}
	if (parent[v] != d_) return;
	while (true){
		int x = s.back();
		s.pop_back();
		color[x] = 2;
		parent[x] = v;
		if (x == v) break;
	}
}

void tarjan(int n){
	memset(color, 0, sizeof color);
	memset(parent, 0, sizeof parent);
	memset(disc, 0, sizeof disc);
	s.resize(0);
	for (int i = 1; i <= n; i++)
		graph[0].push_back(i);
	int d = 0;
	t_dfs(0, d);
}

int main(){ _
	int n, m;
	while (true){
		cin >> n >> m;
		if ((n+m) == 0) break;
		for (int i = 0; i <= n; i++)
			graph[i].resize(0);
		int v, w, u;
		for (int i = 0; i < m; i++){
			cin >> v >> w >> u;
			graph[v].push_back(w);
			if (u == 2)
				graph[w].push_back(v);

		}
		tarjan(n);
		bool ans = true;
		for (int i = 1; i <= n; i++)
			ans &= parent[i] == parent[1];
		cout << ans << endl;
	}
	return 0;
}

