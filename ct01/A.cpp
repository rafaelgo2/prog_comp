#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int m[1010][1010];
int v[1010];
int sum[1010];

int main(){ _
	int p, n, c;
	while (true){
		cin >> p >> n >> c;
		memset(m, 0, sizeof m);
		memset(v, 0, sizeof v);
		memset(sum, 0, sizeof sum);
		if (p == 0 && n == 0 && c == 0) break;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= p; j++){
				cin >> m[i][j];
				if (m[i][j] == 1)
					sum[j]++;
				else{
					v[sum[j]]++;
					sum[j] = 0;
				}
			}
		}
		for (int j = 1; j <= p; j++)
			v[sum[j]]++;
		int ans = 0;
		for (int j = c; j <= n; j++)
			ans += v[j];
		cout << ans << endl;
	}
	return 0;
}

