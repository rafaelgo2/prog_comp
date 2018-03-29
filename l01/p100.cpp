#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int get(int acc, int n){
	acc++;
	if (n == 1) return acc;
	if (n%2 == 0) return get(acc, n/2);
	else return get(acc, 3*n+1);
}

int main(){ _
	int l, r;
	while (cin >> l >> r){
		cout << l << " " << r << " ";
		if (r < l) swap(l, r);
		int ans = 0;
		for (int i = l; i <= r; i++)
			ans = max(ans, get(0, i));
		cout << ans << endl;
	}
	return 0;
}
