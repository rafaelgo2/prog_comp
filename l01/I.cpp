#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){ _
	string s;
	getline(cin, s);
	while (true){
		while (s.size() != 0){
			int counter = 0;
			//cout << "S: " << s << endl;
			for (int i = 0; i < s.size(); i++){
				if ('0' <= s[i] && s[i] <= '9'){
					counter += s[i] - '0';
					continue;
				}
				if (s[i] == '!'){
					cout << endl;
					continue;
				}
				if (s[i] == 'b') s[i] = ' ';
				for (int k = 0; k < counter; k++)
					cout << s[i];
				counter = 0;
			}
			getline(cin, s);
			if (s.size() != 0) cout << endl;
		}
		cout << endl;
		getline(cin, s);
		if (s.size() != 0) cout << endl;
		else break;
	}
	return 0;
}
