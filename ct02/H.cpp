#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){ _
	int A, D;
	int a[100], d[100];
	while (true){
		cin >> A >> D;
		if (A == 0 && D == 0) break;
		for (int i = 0; i < A; i++) cin >> a[i];
		sort(a, a+A);
		for (int i = 0; i < D; i++) cin >> d[i];
		sort(d, d+D);
		if (a[0] < d[1]) cout << "Y" << endl;
		else cout << "N" << endl;
	}
	return 0;
}
