#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){ _
	int n, v[2];
	cin >> n >> v[0] >> v[1];
	string s;
	cin >> s;

	int last = (v[0] < v[1]) ? 0 : 1;
	int ans = 0;
	for (char c : s){
		if (c == '*'){
			last = (v[0] < v[1]) ? 0 : 1;
			continue;
		}
		int next = !last;
		if (v[next] > 0){
			ans++;
			v[next]--;
			last = next;
		}
		last = next;
	}
	cout << ans << endl;
	return 0;
}
