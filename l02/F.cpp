#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

typedef pair<int, int> pii;
#define u first
#define v second

#define MAXV 100000

typedef vector<int> vi;
vi g[MAXV];


int n, m;

int ans[MAXV];
int color[MAXV];
int parent[MAXV];
int id[MAXV];
int sz;
vector<int> s;

vector<int> ord;

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
		ord.push_back(x);
		if (x == v) break;
	}
}

void tarjan(int n){
	memset(color, 0, sizeof color);
	memset(parent, 0, sizeof parent);
	memset(ans, 0, sizeof ans);
	s.resize(0);
	sz = 0;
	int d = 1;
	for (int i = 0; i < n; i++)
		if (color[i] == 0) t_dfs(i, d);
}


int main(){ _
	cin >> n >> m;
	pii e[110];
	for (int i = 0; i < m; i++){
		cin >> e[i].u >> e[i].v;
		if (e[i].u > e[i].v) swap(e[i].u, e[i].v);
	}
	for (int i = 0; i < m; i++){
		for (int j = i+1; j < m; j++){
			pii l = min(e[i], e[j]);
			pii r = max(e[i], e[j]);
			//cout << l.u << " " << l.v << "vs";
			//cout << r.u << " " << r.v << endl;	
			if ((l.u < r.u) && (r.u < l.v) && (l.v < r.v)){
				//cout << "TRUE" << endl
				g[i].push_back(j+m);
				g[i+m].push_back(j);
				g[j].push_back(i+m);
				g[j+m].push_back(i);
			}
		}
	}
	tarjan(2*m);
	for (int i = 0; i < m; i++){
		if (id[i] == id[i+m]){
			cout << "Impossible" << endl;
			return 0;
		}
	}
	memset(ans, 0, sizeof ans);
	for (int i = ord.size()-1; i >= 0; i--){
		int var = ord[i];
		if (var >= m){
			if (ans[var-m]) continue;
			ans[var] = true;
		}
		else{
			if (ans[var+m]) continue;
			ans[var] = true;
		}	
	}
	for (int i = 0; i < m; i++){
		if (ans[i]) cout << 'i';
		else cout << 'o';
	}
	cout << endl;

	
	return 0;
}

