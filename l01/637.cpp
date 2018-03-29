#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int n;
string fix(int value){
	if (value > n) return "Blank";
	stringstream ss;
	ss << value;
	string s;
	ss >> s;
	return s;
}

int main(){ _
	while (true){
		cin >> n;
		if (n == 0) break;
		int aux = (n/4)*4 + (n%4 != 0)*4;
		vector< vector<int> > v(aux+1);
		int k = 1, inc = 1;
		int i = 1;
		while (i <= aux){
			v[k].push_back(i++);
			v[k].push_back(i++);
			if (k == aux/4){
				inc = -1;
				v[k].push_back(i++);
				v[k].push_back(i++);
			}
			k += inc;
		}
		cout << "Printing order for " << n << " pages:" << endl;
		for (int k = 1; k <= aux/4; k++){
			cout << "Sheet " << k << ", front: ";
			cout << fix(v[k][3]) << ", " << fix(v[k][0]) << endl;
			if (v[k][1] > n)
				continue;
			cout << "Sheet " << k << ", back : ";
			cout << fix(v[k][1]) << ", " << fix(v[k][2]) << endl;
		}


	}
	return 0;
}
