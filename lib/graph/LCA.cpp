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
