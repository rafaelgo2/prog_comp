#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int MAX = 2e4+2;

typedef vector<int> vi;

const int INF = 0x3f3f3f3f;

template<typename T, typename OP> struct seg_tree{
	OP op;
	T t[8*MAX];
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
	LCA(){}
	void init(int root, vi *g_){
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
	int parent_depth[MAX+2][17];
	void make_depth(int n, int root){
		int j = 0; 
		for (int i = 1; i <= n; i++){
			parent_depth[i][j] = parent[i];
		}
		parent_depth[root][j] = -1;
		bool flag = true;
		while (flag){
			j++;
			flag = false;
			for (int i = 1; i <= n; i++){
				int aux = parent_depth[i][j-1];
				if (aux == -1)
					parent_depth[i][j] = -1;
				else {
					parent_depth[i][j] = parent_depth[aux][j-1];
					if (parent_depth[i][j] != -1)
						flag = true;
				}
			}
		}
	}
	int get_depth(int i){
		return depth[occ[i]].first;
	}
};


typedef pair<int, int> pii;

pii dfs_diam(int i, int v, vi *g, int d){
	pii ans(d, i);
	for (int n : g[i]){
		if (n == v) continue;
		ans = max(ans, dfs_diam(n, i, g, d+1));
	}
	return ans;
}
pair<int, int> get_diam(vi *g){
	pii l = dfs_diam(1, -1, g, 0);
	pii r = dfs_diam(l.second, -1, g, 0);
	return make_pair(l.second, r.second);
}

LCA lcaL;
LCA lcaR;

int main(){ _
	static vi g[MAX];
	int n, q, l, r;
	cin >> n >> q;
	for (int i = 1; i < n; i++){
		cin >> l >> r;
		g[l].push_back(r);
		g[r].push_back(l);
	}
	auto diam = get_diam(g);
	lcaL.init(diam.first, g);
	lcaL.make_depth(n, diam.first);
	lcaR.init(diam.second, g);
	lcaR.make_depth(n, diam.second);
	for (int i = 0; i < q; i++){
		cin >> l >> r;
		char c;
		int dist_L = lcaL.get_depth(l);
		int dist_R = lcaR.get_depth(l);
		if (dist_L >= r){
			int it = 0;
			while (r != 0){
				if ((r&(1 << it)) != 0){
					l = lcaL.parent_depth[l][it];
					r -= (1 << it);
				}
				it++;
			}
			cout << l << endl;
		}
		else if (lcaR.get_depth(l) >= r){
			int it = 0;
			while (r != 0){
				if ((r&(1 << it)) != 0){
					l = lcaR.parent_depth[l][it];
					r -= (1 << it);
				}
				it++;
			}
			cout << l << endl;
		}
		else cout << 0 << endl;
	}
	return 0;
}

