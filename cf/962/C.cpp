#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int MAXN = 2e9;

int main(){ _
	string s;
	cin >> s;
	int ans = MAXN;
	for (int i = 1; i*i <= MAXN; i++){
		stringstream ss;
		ss << i*i;
		string n;
		ss >> n;
		int in = 0;
		int tmp = 0;
		for (char c : s){
			if (in != n.size() && (c == n[in]))
				in++;
			else
				tmp++;
		}
		if (in == n.size()){
			ans = min(ans, tmp);
		}
	}
	if (ans == MAXN) cout << -1 << endl;
	else cout << ans << endl;
	return 0;
}
