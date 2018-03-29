#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

typedef vector<int> vi;
#define MAXV 9999

vi g[MAXV];
int color[MAXV];
int parent[MAXV];
int id[MAXV];
int sz;
vector<int> s;

void t_dfs(int v, int &d){
	parent[v] = d++;
	int d_ = parent[v];
	s.push_back(v);
	color[v] = 1;
	for (int w : g[v]){
		if (color[w] == 2) continue;
		if (color[w] == 0)
			t_dfs(w, d);
		parent[v] = min(parent[v], parent[w]);
	}
	if (parent[v] != d_) return;
	int id_ = sz++;
	while (true){
		int x = s.back();
		s.pop_back();
		color[x] = 2;
		id[x] = id_;
		if (x == v) break;
	}
}

void tarjan(int n){
	memset(color, 0, sizeof color);
	memset(parent, 0, sizeof parent);
	s.resize(0);
	sz = 0;
	int d = 1;
	for (int i = 1; i <= n; i++)
		if (color[i] == 0) t_dfs(i, d);
}

int main(){ _
	int n, m;
	while (true){
		cin >> n >> m;
		if ((n+m) == 0) break;
		for (int i = 0; i <= n; i++)
			g[i].resize(0);
		int v, w, u;
		for (int i = 0; i < m; i++){
			cin >> v >> w >> u;
			g[v].push_back(w);
			if (u == 2)
				g[w].push_back(v);

		}
		tarjan(n);
		cout << (sz == 1) << endl;
	}
	return 0;
}

