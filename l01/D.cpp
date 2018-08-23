#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){ _
	int n;
	int ans[20];
	string s, r;
	cin >> n;
	while (true){
		memset(ans, 0, sizeof ans);
		map<int, string> back_id;
		map<string, int> id;
		for (int i = 0; i < n; i++){
			cin >> s;
			id[s] = i;
			back_id[i] = s;
		}
		for (int i = 0; i < n; i++){
			cin >> s;
			int k, m;
			cin >> k >> m;

			if (m == 0) ans[id[s]] += k;
			else ans[id[s]] += k%m;

			ans[id[s]] -= k;


			for (int j = 0; j < m; j++){
				cin >> r;
				ans[id[r]] += k/m;
			}
		}
		for (int i = 0; i < n; i++)
			cout << back_id[i] << " " << ans[i] << endl;
		if (cin >> n)
			cout << endl;
		else
			break;
	}
	
	return 0;
}
