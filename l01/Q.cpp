#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

#define MAX_ITEMS 110
struct union_find{
	int id[MAX_ITEMS];
	void init(int n){
		for (int i = 0; i <= n; i++)
			id[i] = i;
	}
	int get_id(int i){
		if (id[i] == i)	return i;
		return id[i] = get_id(id[i]);
	}
	void join(int l, int r){
		int id_l = get_id(l);
		int id_r = get_id(r);
		id[id_l] = id_r;
	}
};

typedef pair<int, int> pii;

int main(){ _
	int n, m, q;
	union_find uf;
	vector<pair<int, pii> > edge;
	int c = 1;
	while (true){
		cin >> n >> m >> q;
		if ((n+m+q) == 0) break;
		if (c > 1) cout << endl;

		edge.resize(0);
		int u, v, w;
		for (int i = 0; i < m; i++){
			cin >> u >> v >> w;
			edge.push_back(pair<int, pii>(w, pii(u, v)));
		}
		sort(edge.begin(), edge.end());

		cout << "Case #" << c++ << endl;
		for (int i = 0; i < q; i++){
			cin >> u >> v;
			uf.init(n);
			int ans = -1;
			for (pair<int, pii> p : edge){
				pii uv = p.second;
				if (uf.get_id(uv.first) == uf.get_id(uv.second))
					continue;
				ans = max(ans, p.first);
				uf.join(uv.first, uv.second);
				if (uf.get_id(u) == uf.get_id(v)) break;
			}
			if (uf.get_id(u) != uf.get_id(v))
				cout << "no path" << endl;
			else
				cout << ans << endl;
		}

					
	}
	return 0;
}
