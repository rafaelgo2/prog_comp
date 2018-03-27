#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
#define MAXV 3000
#define INF 99999999

int f[MAXV+1][MAXV+1];
int c[MAXV+1][MAXV+1];
vi g[MAXV+1];

void init(int n){
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			f[i][j] = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			c[i][j] = 0;
	for (int i = 0; i < n; i++)
		g[i].resize(0);
}

void add_edge(int v, int w, int cap){
	c[v][w] += cap;
	c[w][v] += cap;
	f[w][v] += cap;
	g[v].push_back(w);
	g[w].push_back(v);
}

int max_flow(int from, int to, int n){
	int ans = 0;
	static vector<int> q;
	static int parent[MAXV+1];
	while (true){
		q.resize(0);
		memset(parent, -1, n*sizeof(int));
		parent[from] = from;
		q.push_back(from);
		while (q.size() > 0){
			int v = q.back(); q.pop_back();
			if (v == to) break;
			for (int w : g[v]){
				if ((parent[w] == -1) && ((c[v][w] - f[v][w]) > 0)){
					parent[w] = v;
					q.push_back(w);
				}
			}
		}
		if (parent[to] == -1) break;
		int inc = INF;
		int i = to;
		while (parent[i] != i){
			inc = min(inc, c[parent[i]][i] - f[parent[i]][i]);
			i = parent[i];
		}
		i = to;
		while (parent[i] != i){
			f[parent[i]][i] += inc;
			f[i][parent[i]] -= inc;
			i = parent[i];
		}
		ans += inc;
	}
	return ans;
}

int main(){ _
	int n, m, k, inst = 1;
	while (cin >> n >> m >> k){
		init(n+m+2);
		int sum_in = 0;
		for (int i = 1; i <= n; i++){
			int cap;
			cin >> cap;
			add_edge(0, i, cap);
		}
		while (k--){
			int v, w;
			cin >> v >> w;
			add_edge(v, n+w, 1);
		}
		for (int i = 1; i <= m; i++){
			add_edge(n+i, n+m+1, 1);
		}
		cout << "Instancia " << inst++ << endl
			 << max_flow(0, n+m+1, n+m+2) << endl << endl;
	}
	return 0;
}
