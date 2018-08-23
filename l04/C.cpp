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
	int t;
	cin >> t;
	while (t--){
		int N;
		double d;
		cin >> N >> d;
		MaxFlow mf(1+N+N);
		int sum = 0;
		vector<int> x(1+N);
		vector<int> y(1+N);

		for (int i = 1; i <= N; i++){
			int n, m;
			cin >> x[i] >> y[i] >> n >> m;
			mf.addEdge(0, i, n);
			sum += n;
			mf.addEdge(i, i+N, m);
		}
		for (int i = 1; i <= N; i++){
			for (int j = i+1; j <= N; j++){
				if (hypot(x[i]-x[j], y[i]-y[j]) <= d+1e-7){
					mf.addEdge(i+N, j, sum);
					mf.addEdge(j+N, i, sum);
				}
			}
		}
		vector<int>	ans;
		for (int i = 1; i <= N; i++){
			MaxFlow x = mf;
			int f = x.maxFlow(0, i);
			if (f == sum)
				ans.push_back(i);
		}
		if (ans.size() == 0) cout << "-1" << endl;
		else{
			cout << ans.front()-1;
			for (int i = 1; i < ans.size(); i++) cout << " " << ans[i]-1;
			cout << endl;
		}
	}
	return 0;
}

