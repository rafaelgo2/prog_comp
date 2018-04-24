#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int n, A, B, C, T;
int t[1010];

int main(){ _
	cin >> n >> A >> B >> C >> T;
	for (int i = 0; i < n; i++) cin >> t[i];
	int ans = A*n;
	int inc = C-B;
	for (int i = 0; i < n; i++)
		ans += max(0, (T-t[i])*inc);
	cout << ans << endl;	
	return 0;
}
