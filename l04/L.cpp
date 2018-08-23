#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

struct Edge {
	int v, rev;
	int cap;
	Edge(int v_, int cap_, int rev_) : v(v_), rev(rev_), cap(cap_) {}
};

struct MaxFlow {
	vector<vector<Edge> > g;
	vector<int> level;
	queue<int> q;
	int flow, n;

	MaxFlow(int n_) : g(n_), level(n_), n(n_) {}
	void addEdge(int u, int v, int cap)
	{
		if (u == v) return;
		Edge e(v, cap, int(g[v].size()));
		Edge r(u, 0, int(g[u].size()));
		g[u].push_back(e);
		g[v].push_back(r);
	}

	bool buildLevelGraph(int src, int sink)
	{
		fill(level.begin(), level.end(), -1);
		while (not q.empty()) q.pop();
		level[src] = 0;
		q.push(src);
		while (not q.empty()) {
			int u = q.front();
			q.pop();
			for (auto e = g[u].begin(); e != g[u].end(); ++e) {
				if (not e->cap or level[e->v] != -1) continue;
				level[e->v] = level[u] + 1;
				if (e->v == sink) return true;
				q.push(e->v);
			}
		}
		return false;
	}

	int blockingFlow(int u, int sink, int f)
	{
		if (u == sink or not f) return f;
		int fu = f;
		for (auto e = g[u].begin(); e != g[u].end(); ++e) {
			if (not e->cap or level[e->v] != level[u] + 1) continue;
			int mincap = blockingFlow(e->v, sink, min(fu, e->cap));
			if (mincap) {
				g[e->v][e->rev].cap += mincap;
				e->cap -= mincap;
				fu -= mincap;
			}
		}
		if (f == fu) level[u] = -1;
		return f - fu;
	}

	int maxFlow(int src, int sink)
	{
		flow = 0;
		while (buildLevelGraph(src, sink))
			flow += blockingFlow(src, sink, numeric_limits<int>::max());
		return flow;
	}
};


int main(){ _
	int n, m;
	cin >> n >> m;
	MaxFlow mf(1+n+n+1);
	for (int i = 1; i <= n; i++){
		mf.addEdge(0, i, 1);
		mf.addEdge(i+n, n+n+1, 1);
	}
	while (m--){
		int a, b;
		cin >> a >> b;
		mf.addEdge(a+1, b+1+n, 1);
	}
	int it = mf.maxFlow(0, n+n+1);
	if (it == n) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}

