#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int n, m;
int t[30][30];

bool valid(int i, int j){
	if (i <= 0 || i > n) return false;
	if (j <= 0 || j > m) return false;
	return true;
}

int func(int i, int j){
	int ans = 0;
	for (int i_ = -2; i_ <= 2; i_+= 4){
		for (int j_ = -2; j_ <= 2; j_+=4){
			if (!valid(i+i_, j+j_)) continue;
			if (t[i+i_][j+j_] != 0) continue;
			if (t[i+(i_/2)][j+(j_/2)] != 2) continue;
			t[i][j] = 0;
			t[i+(i_/2)][j+(j_/2)] = 0;
			t[i+i_][j+j_] = 1;
			ans = max(ans, 1+func(i+i_, j+j_));
			t[i+i_][j+j_] = 0;
			t[i+(i_/2)][j+(j_/2)] = 2;
			t[i][j] = 1;
		}
	}
	return ans;
}

int main(){ _
	while (true){
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		memset(t, -1, sizeof t);
		for (int i = 1; i <= n; i++){
			for (int j = (i%2) ? 1 : 2; j <= m; j += 2){
				cin >> t[i][j];
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				if (t[i][j] == 1)
					ans = max(ans, func(i, j));
			}
		}
		cout << ans << endl;	
	}
	return 0;
}

