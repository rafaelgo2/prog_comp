#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){ _
	int n;
	while (true){
		cin >> n;
		if (n==0) break;
	
		int v = ceil(sqrt(n));
		int mid = v*v - v + 1;

		int i = v, j = v - abs(mid - n);
		if (n < mid) swap(i, j);
		if (v%2 == 1) swap(i, j);
		cout << i << " " <<  j << endl;
	}
	return 0;
}
