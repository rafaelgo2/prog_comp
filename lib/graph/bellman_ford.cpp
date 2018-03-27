#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

#define MAXSZ 300
#define INFTY (200*200*200 + 10)
typedef pair<int, int> pii;
typedef pair<int, pii> edge;
#define weight first
#define from second.first
#define to second.second

int d[MAXSZ];
void shortest_path(vector<edge> &g, int f, int n){
	for (int i = 0; i <= n; i++)
		d[i] = INFTY;
	d[f] = 0;
	for (int i = 0; i < n; i++){
		for (edge e : g){
			if (d[e.from] == INFTY)
				continue;
			d[e.to] = min(d[e.to], d[e.from] + e.weight);
		}
	}
	for (edge e : g)
		if (d[e.to] > d[e.from] + e.weight && d[e.from] != INFTY)
			d[e.to] = -INFTY;
}

int main(){ _
	int aux = 1, n;
	int b[MAXSZ], r, q;
	vector<edge> g;
	while(cin >> n){
		g.resize(0);
		for (int i = 1; i <= n; i++)
			cin >> b[i];
		cin >> r;
		for (int i = 0; i < r; i++){
			int f, t;
			cin >> f >> t;
			int delta = b[t]-b[f];
			g.push_back(edge(delta*delta*delta, pii(f, t)));
		}
		cout << "Set #" << aux++ << endl;
		shortest_path(g, 1, n);
		cin >> q;
		for (int i = 0; i < q; i++){
			int v;
			cin >> v;
			if (d[v] < 3 || d[v] == INFTY)
				cout << "?" << endl;
			else
				cout << d[v] << endl;
		}
	}
	return 0;
}
