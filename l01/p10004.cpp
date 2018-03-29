#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

#define MAXV 210

typedef vector<int> vi;

int main(){ _
	int n, m;
	vi graph[MAXV];
	int type[MAXV];
	while (true){
		cin >> n;
		if (n == 0) break;
		cin >> m;

		for (int i = 0; i <= n; i++){
			graph[i].resize(0);
			type[i] = -1;
		}

		int v, w;
		for (int i = 0; i < m; i++){
			cin >> v >> w;
			graph[v].push_back(w);
			graph[w].push_back(v);
		}

		queue<int> q; q.push(1);
		type[1] = 0;
		bool flag = true;
		while (!q.empty()){
			v = q.front(); q.pop();
			for (int i : graph[v]){	
				if (type[i] == type[v]) flag = false;
				if (type[i] == -1){
					type[i]	= !type[v];
					q.push(i);
				}
			}
		}
		if (!flag) cout << "NOT ";
		cout << "BICOLORABLE." << endl;
	}
	return 0;
}
