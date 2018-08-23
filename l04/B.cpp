#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

bool v[310][310];

int mem_L[310][310];
int mem_SQ[310][310];

int sum_L(int x, int y){
	if (x < 0 || y < 0) return 0;
	if (mem_L[x][y] == -1)
		mem_L[x][y] = sum_L(x-1, y) + v[y][x];
	return mem_L[x][y];
}

int sum_SQ(int x, int y){
	if (x < 0 || y < 0) return 0;
	if (mem_SQ[x][y] == -1)
		mem_SQ[x][y] = sum_L(x, y) + sum_SQ(x, y-1);
	return mem_SQ[x][y];
}

int area(int l, int r, int u, int d){
	return sum_SQ(r, d) - sum_SQ(l-1, d) - sum_SQ(r, u-1) + sum_SQ(l-1, u-1);
}

int main(){ _
	int n, m, k;
	while (true){
		cin >> n >> m >> k;
		if (n+m+k == 0) break;
		char c;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				cin >> c;
				v[i][j] = (c == '.');
			}
		}
		memset(mem_L, -1, sizeof mem_L);
		memset(mem_SQ, -1, sizeof mem_SQ);
//	for (int u = 0; u < n; u++){
//		for (int l = 0; l < m; l++){
//			cout << area(0, l, 0, u) << "(" << (l-0+1)*(u-0+1) << ") " ;
//		}
//		cout << endl;
//	}
		int ans = n*m;
		for (int l = 0; l < m; l++){
			for (int r = l; r < m; r++){
				int u = 0, d = 0;
				while (true){
					while (d+1 < n && area(l, r, u, d) < k)
						d++;
					if (area(l, r, u, d) < k) break;
					ans = min(ans, (r-l+1)*(d-u+1));
				//	cout << l << " " << r << " " << u << " " << d << " " << area(l, r, u, d) << endl;
					u++;
					if (u == n) break;
				}
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}
