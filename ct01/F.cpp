#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){ _
	int t, n;
	string s;
	while (true){
		cin >> t >> n;
		if (t == 0) break;
		int sum = 0, aux;
		for (int i = 0; i < t; i++){
			cin >> s >> aux;
			sum += aux;
		}
		cout << (3*n - sum) << endl;
	}
	return 0;
}

