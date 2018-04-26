#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

typedef long long int lli;

int main(){ _
	int n;
	cin >> n;
	lli v[200010];
	lli sum = 0.0;
	for (int i = 0; i < n; i++){
		cin >> v[i];
		sum += v[i];
	}
	lli half = (sum + 1)/2;
	sum = 0.0;
	for (int i = 0; i < n; i++){
		sum += v[i];
		if (sum >= half){
			cout << i+1 << endl;
			return 0;
		}
	}

	return 0;
}
