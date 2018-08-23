#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){ _
	string s;
	bool flag = true;
	while (getline(cin , s)){
		for (char c : s){
			if (c == '"'){
				if (flag) cout << "``";
				else cout << "''";
				flag = !flag;
			}
			else
				cout << c;
		}
		cout << endl;
	}
	return 0;
}
