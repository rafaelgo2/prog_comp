#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAX = 1e3+10;


string l, r;
int k;

int memo_g[MAX][MAX];
int get_g(int i, int j){
	if (k == 0) return 0;
	if (i == l.size() || j == r.size()) return 0;
	if (memo_g[i][j] == -1){
		if (l[i] == r[j])
			memo_g[i][j] = 1 + get_g(i+1, j+1);
		else
			memo_g[i][j] = 0;
	}
	return memo_g[i][j];
}

int memo[MAX][MAX];
int get(int i, int j){
	if (i == l.size() || j == r.size()) return 0;
	if (memo[i][j] == -1){
		int ans = 0;
		ans = max(ans, get(i+1, j));
		ans = max(ans, get(i, j+1));
		ans = max(ans, get(i+1, j+1));
		int it = get_g(i, j);
		if (it >= k){
			ans = max(ans, it + get(i+it, j+it));
			ans = max(ans, k + get(i+k, j+k));
		}
		memo[i][j] = ans;
	}
	return memo[i][j];
}

int main(){ _
	while (true){
		cin >> k;
		if (k == 0) break;
		cin >> l >> r;
		memset(memo, -1, sizeof memo);
		memset(memo_g, -1, sizeof memo_g);
		cout << get(0, 0) << endl;
	}
	return 0;
}

