#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

#define MAXV 1010

int n, m;
typedef vector<int> vi;
vi g[MAXV];


int color[MAXV];
int parent[MAXV];
int id[MAXV];
int sz;
vector<int> s;

void t_dfs(int v, int ant, int &d){
	parent[v] = d++;
	int d_ = parent[v];
	s.push_back(v);
	color[v] = 1;
	for (int w : g[v]){
		if (w == ant) continue;
		if (color[w] == 2) continue;
		if (color[w] == 0)
			t_dfs(w, v, d);
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
		if (color[i] == 0) t_dfs(i, -1, d);
}


int main(){ _
	while (true){
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		for (int i = 1; i <= n; i++)
			g[i].resize(0);
		int u, w;
		for (int i = 0; i < m; i++){
			cin >> u >> w;
			g[u].push_back(w);
			g[w].push_back(u);
		}
		tarjan(n);

		//bool ans = true;
		//for (int i = 1; i <= n; i++)
			//ans &= (p[i] == p[init]);
		if (sz == 1) cout << "S" << endl;
		else cout << "N" << endl;
	}
	return 0;
}

