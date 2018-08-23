#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

#define MAXP 110

typedef pair<double, double> pdd;
pdd p[MAXP];
#define x first
#define y second

typedef pair<int, int> pii;
vector<pair<double, pii>> v;

#define MAX_ITEMS 110

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
	int n;
	cin >> n;
	union_find uf;
	cout << fixed << setprecision(2); 
	while (n--){
		int m;
		cin >> m;
		for (int i = 0; i < m; i++)
			cin >> p[i].x >> p[i].y;
		
		v.resize(0);
		for (int i = 0; i < m; i++){
			for (int j = i+1; j < m; j++){
				double w = hypot(p[i].x - p[j].x, p[i].y - p[j].y);
				v.push_back(pair<double, pii>(w, pii(i, j)));
			}
		}
		sort(v.begin(), v.end());
		uf.init(m);
		double ans = 0.0;
		for (pair<double, pii> pdii : v){
			pii cur = pdii.second;
			if (uf.get_id(cur.first) == uf.get_id(cur.second)) continue;
			ans += pdii.first;
			uf.join(cur.first, cur.second);
		}
		cout << ans << endl;
		if (n != 0) cout << endl;
	}
	return 0;
}
