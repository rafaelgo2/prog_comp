#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int MAX = 5e4+10;

const int INF = 0x3f3f3f3f;

typedef vector<int> vi;

//Potentiometer UVA
//Interval Product LiveArchive
//LCA SPOJ
template<typename T, typename OP> struct seg_tree{
	OP op;
	T t[10*MAX];
	int n;
	int L, R;
	T *v;
	T build(int l, int r, int i){
		if (l == r) return t[i] = op(v[l]);
		int m = (l+r)/2;
		T lb = build(l, m, 2*i+1);
		T rb = build(m+1, r, 2*i+2);
		return t[i] = op(lb, rb);
	}
	T query(int l, int r, int i){
		if (L <= l && r <= R) return t[i];
		int m = (l+r)/2;
		if (m >= R) return query(l, m, 2*i+1);
		if (m < L) return query(m+1, r, 2*i+2);
		return op(query(l, m, 2*i+1), query(m+1, r, 2*i+2));
	}
	T query(int L_, int R_){
		L = L_;
		R = R_;
		return query(0, n-1, 0);
	}
	T update(int l, int r, int i, int k){
		if (l == r) return t[i] = op(v[k]);
		int m = (l+r)/2;
		if (m >= k) return t[i] = op(t[2*i+2], update(l, m, 2*i+1, k));
		if (m < k) return t[i] = op(t[2*i+1], update(m+1, r, 2*i+2, k));
		return t[i] = op(update(l, m, 2*i+1, k), update(m+1, r, 2*i+2, k));
	}
	T update(int k){
		return update(0, n-1, 0, k);
	}
	seg_tree(T* v_, int n_){
		v = v_;
		n = n_;
		build(0, n-1, 0);
	}
	seg_tree(){}
};

template<typename T> struct min_el{
	T operator()(const T& l){
		return l;
	}
	T operator()(const T& l, const T& r){
		return min(l, r);
	}
};

struct LCA{
	pair<int, int> depth[2*MAX+2];
	int occ[2*MAX+2];
	int parent[2*MAX+2];
	seg_tree<pair<int, int>, min_el<pair<int, int>>> st;
	vi *g;
	void euler(int v, int u, int &d, int &i){
		parent[v] = u;
		occ[v] = i;
		depth[i++] = make_pair(d++, v);
		for (int j : g[v]){
			if (j == u) continue;
			euler(j, v, d, i);
			depth[i++] = make_pair(d-1, v);
		}
		d--;
	}
	LCA(int root, vi *g_){
		g = g_;
		int maxVD = 0;
		int d = 0;
		memset(depth, INF, sizeof depth);
		euler(root, -1, d, maxVD);
		st = seg_tree<pair<int, int>, min_el<pair<int, int>>>(depth, maxVD);
	}
	int get(int l, int r){
		int iL = occ[l];
		int iR = occ[r];
		if (iL > iR) swap(iL, iR);
		return st.query(iL, iR).second;
	}
};


vi g[MAX];

typedef long long int lli;

lli c[MAX], v[MAX];

lli inc[MAX];
lli p[MAX];
lli make_p(int v, int u){
	p[v] = inc[v];
	for (int i : g[v]){
		if (i == u) continue;
		p[v] += make_p(i, v);
	}
	return p[v];
}

lli memo[MAX][1010];
lli get_dp(int i, int d){
	if (i == -1) return 0;
	if (memo[i][d] == -1){
		int id = c[i];
		lli ans = get_dp(i-1, d);
		if (d >= v[i])
			ans = max(ans, p[id] + get_dp(i-1, d-v[i]));
		memo[i][d] = ans;
	}
	return memo[i][d];
}

int main(){ _
	memset(memo, -1, sizeof memo);
	int n, d, m, q;
	cin >> n >> d;
	int x, y, w;
	for (int i = 1; i < n; i++){
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	g[0].push_back(1);
	cin >> m;
	for (int i = 0; i < m; i++)
		cin >> c[i] >> v[i];
	LCA lca(0, g);
	cin >> q;
	memset(inc, 0, sizeof inc);
	memset(p, 0, sizeof p);
	for (int i = 0; i < q; i++){
		cin >> x >> y >> w;
		int z = lca.get(x, y);
		inc[x] += w;
		inc[y] += w;
		inc[z] -= w;
		inc[lca.parent[z]] -= w;
	}
	make_p(0, -1);
	cout << get_dp(m-1, d) << endl;
	return 0;
}


