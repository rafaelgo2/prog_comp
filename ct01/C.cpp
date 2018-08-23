#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int g[1010][1010];

int INF = 99999999;

int main(){ _
	while (true){
		int n, e; 
		cin >> n >> e;
		if (n == 0 && e == 0) break;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				g[i][j] = INF;
		int x, y, h;
		for (int i = 0; i < e; i++){
			cin >> x >> y >> h;
			g[x][y] = min(g[x][y], h);
		}
		
		for (int i = 1; i <= n; i++)
			g[i][i] = 0;
		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (g[i][j] < INF && g[j][i] < INF) g[i][j] = 0;
		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

		int k, o, d;
		cin >> k;
		for (int i = 0; i < k; i++){
			cin >> o >> d;
			if (g[o][d] >= INF){
				cout << "Nao e possivel entregar a carta" << endl;
				continue;
			}
			cout << g[o][d] << endl;	
		}
		cout << endl;
	}
	return 0;
}

