#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

#define MAX 1450

int c, n, m, t;
int v[MAX];


int main(){ _
	cin >> c;
	while (c--){
		cin >> n >> t >> m;
		v[0] = -2*t;
		for (int i = 1; i <= m; i++)
			cin >> v[i];

		int ans = v[m%n] + 2*t, ans_ = m%n != 0;
		int qt = 0;
		for (int i = (m%n) + 1; i <= m; i++){
			qt++;
			if (qt == n){
				ans = max(ans, v[i]) + 2*t;	
				ans_++;
				qt = 0;
			}	
		}
		cout << ans-t << " " << ans_ << endl;
	}
	return 0;
}
