#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

typedef long long int lli;
typedef vector<int> vi;
struct edge{
	int u, v, w;
};
typedef pair<int, int> pii;

#define MAXV 1000010

int n, m;
vi g[MAXV];
vector<pii> dag[MAXV];
edge e[MAXV];
lli w[MAXV];

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

lli qt(lli y){
	lli a = 1, b = 1, c = -2*y;
	double delta = b*b - 4*a*c;
	return ceil((-b + sqrt(delta)) / 2*a);
}

lli get_w(lli y){
	lli q = qt(y);
	lli ans = y*q;
	q--;
	ans -= (q*(q+1)*(q+2))/6;
	return ans;
	lli i = 0, inc = 1;
	while (true){
		if (i > y) break;
		ans += y - i;
		i += inc;
		inc ++;
	}
	return ans;
}


lli memo[MAXV];
lli get(int x){
	if (memo[x] == -1){
		lli ans = 0;
		for (pii p : dag[x])
			ans = max(ans, get(p.first) + p.second);
		memo[x] = ans + w[x];
	}
	return memo[x];
}

int main(){ _
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		cin >> e[i].u >> e[i].v >> e[i].w;
		g[e[i].u].push_back(e[i].v);
	}
	memset(memo, -1, sizeof memo);
	int source;
	cin >> source;
	tarjan(n);
	for (int i = 0; i < m; i++){
		int u = e[i].u, v = e[i].v;
		lli tmp = get_w(e[i].w);
		if (id[u] == id[v])
			w[id[u]] += tmp;
		else
			dag[id[u]].push_back(
					pii(id[v], e[i].w)
			);
	}
	cout << get(id[source]) << endl;
	
	return 0;
}

