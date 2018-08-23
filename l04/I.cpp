#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

struct Edge {
	int v, rev;
	int cap;
	Edge(int v_, int cap_, int rev_) : v(v_), rev(rev_), cap(cap_) {}
	Edge(){}
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

const int MAXN = 610;
const int MAXM = 410;

int n, m;
int c[MAXN];
int p[MAXM];
int b[MAXM];
int t[MAXM][MAXM];

const int INF = 0x3f3f3f3f;

int main(){ _
	while (cin >> n >> m){
		for (int i = 1; i <= n; i++) cin >> c[i];
		for (int i = 1; i <= m; i++) cin >> p[i];
		for (int i = 1; i <= m; i++){
			cin >> b[i];
			for (int j = 1; j <= p[i]; j++)
				cin >> t[i][j];
		}
		int lim = 0;
		MaxFlow mf(1+m+n+1);
		for (int i = 1; i <= m; i++){
			mf.addEdge(0, i, b[i]);
			lim += b[i];
			for (int j = 1; j <= p[i]; j++)
				mf.addEdge(i, m+t[i][j], INF);
		}
		for (int i = m+1; i <= m+n; i++){
			mf.addEdge(i, m+n+1, c[i-m]);
		}
		int flow = mf.maxFlow(0, m+n+1);
		cout << lim-flow << endl;
	}
	return 0;
}

