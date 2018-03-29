#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){ _
	int n;
	while (true){
		cin >> n;
		if (n == 0) break;
		vector<int> s_;
		for (int i = 1; i <= n; i++)
			s_.push_back(i);
		for (int m = 1; m <= n; m++){
			vector<int> s = s_;
			int i = 0;
			while (true){
				int v = s[i];
				s.erase(s.begin() + i);
				if (v == 13) break;
				i = (i+m-1)%s.size();
			}
			if (s.size() == 0){
				cout << m << endl;
				break;
			}
		}

	}
	return 0;
}
