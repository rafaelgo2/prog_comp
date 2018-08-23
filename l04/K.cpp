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


typedef long long int lli;
map<lli, int> v;
int get_v(lli i){
	auto it = v.find(i);
	if (it != v.end()) return it->second;
	int id = v.size();
	v[i] = id;
	return id;
}

int main(){ _
	int n;
	cin >> n;
	MaxFlow mf(4*n+10);
	vector<pair<int, int>> w(n+1);
	for (int i = 1; i <= n; i++){
		mf.addEdge(0, i, 1);
		cin >> w[i].first >> w[i].second;
		lli sum  = lli(w[i].first) + lli(w[i].second);
		lli dif  = lli(w[i].first) - lli(w[i].second);
		lli prod = lli(w[i].first) * lli(w[i].second);
		mf.addEdge(i, 1+n+get_v(sum), 1);
		mf.addEdge(i, 1+n+get_v(dif), 1);
		mf.addEdge(i, 1+n+get_v(prod), 1);
	}
	int sink = 4*n+1;
	for (auto it : v)
		mf.addEdge(1+n+it.second, sink, 1);
	int flow = mf.maxFlow(0, sink);
	if (flow != n){
		cout << "impossible" << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++){
		lli sum  = lli(w[i].first) + lli(w[i].second);
		lli dif  = lli(w[i].first) - lli(w[i].second);
		lli prod = lli(w[i].first) * lli(w[i].second);
		int sum_id = 1+n+get_v(sum);
		int dif_id = 1+n+get_v(dif);
		int prod_id = 1+n+get_v(prod);
		for (Edge &e : mf.g[i]){
			if (e.cap != 0) continue;
			if (e.v == sum_id)
				cout << w[i].first << " + " << w[i].second << " = " << sum << endl; 
			else if (e.v == dif_id)
				cout << w[i].first << " - " << w[i].second << " = " << dif << endl; 
			else if (e.v == prod_id)
				cout << w[i].first << " * " << w[i].second << " = " << prod << endl; 
		}
	}
	return 0;
}

