#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main(){
	int T;
	cin >> T;
	while (T--){
		int n, m;
		int a[60][60];
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> a[i][j];
		int ans = 0;
		for (int i = 0; i < n; i++){
			int mx = a[i][m-1];
			for (int j = m-2; j >= 0; j--){
				if (a[i][j] <= mx)
					mx = a[i][j] - 1;
				else
					mx = a[i][j];
			}
			ans ^= mx;
		}
		if (ans == 0)
			cout << "SECOND" << endl;
		else
			cout << "FIRST" << endl;
	}
	return 0;
}
