#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

#define MAX_ITEMS 50010

struct union_find{
	int id[MAX_ITEMS];
	void init(int n){
		for (int i = 0; i <= n; i++)
			id[i] = i;
	}
	int get_id(int i){
		if (id[i] == i)
			return i;
		id[i] = get_id(id[i]);
		return id[i];
	}
	void join(int l, int r){
		int id_l = get_id(l);
		int id_r = get_id(r);
		id[id_l] = id_r;
	}
};

int main(){ _
	int n, m, k = 1;
	int l, r;
	union_find uf;
	while (true){
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		uf.init(n);
		while (m--){
			cin >> l >> r;
			uf.join(l, r);
		}
		set<int> s;
		for (int i = 1; i <= n; i++)
			s.insert(uf.get_id(i));
		cout << "Case " << k++ << ": " << s.size() << endl;
	}
	return 0;
}
