#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int memo_slump[70][70];
bool is_slump(string &s, int l, int r){
	if (l >= r) return false;
	if (memo_slump[l][r] == -1){
		bool flag = false;
		if ((s[l] == 'D' || s[l] == 'E') && s[l+1] == 'F'){
			int i = 1;
			while(l+i <= r && s[l+i] == 'F')
				i++;
			if (l+i == r && s[r] == 'G') flag = true;
			else if (is_slump(s, l+i, r)) flag = true;
		}
		memo_slump[l][r] = flag;
	}
	return memo_slump[l][r];
}

int memo_slimp[70][70];
bool is_slimp(string &s, int l, int r){
	if (l >= r) return false;
	if (memo_slimp[l][r] == -1){
		bool flag = false;
		if (s[l] == 'A'){
			if (l+1 == r && s[r] == 'H') flag = true;
			else if (s[r] == 'C'){
				if (s[l+1] == 'B' && is_slimp(s, l+2, r-1)) flag = true;
				else if (is_slump(s, l+1, r-1)) flag = true;
			}
		}
		memo_slimp[l][r] = flag;
	}
	return memo_slimp[l][r];
}


int main(){ _
	int n;
	cin >> n;
	cout << "SLURPYS OUTPUT" << endl;
	string s;
	while(cin >> s){
		bool flag = false;
		memset(memo_slimp, -1, sizeof memo_slimp);
		memset(memo_slump, -1, sizeof memo_slump);
		for (int i = 0; i < s.size(); i++){
			if (is_slimp(s, 0, i) && is_slump(s, i+1, s.size()-1)){
				flag = true;
				break;
			}
		}
		if (flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	cout << "END OF OUTPUT" << endl;
	return 0;
}
