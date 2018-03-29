#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

#define MAXC 110
#define MAXR 1010

int main(){ _
	int t; cin >> t;
	int out[MAXC];
	int count[MAXC];
	int v[MAXR][MAXC];
	while (t--){
		int n; cin >> n;
		cin.ignore();
		string s;
		map<int, string> conv;
		for (int i = 1; i <= n; i++){
			getline(cin, s);
			conv[i] = s;
		}
		int m = 0;
		while (true){
			getline(cin, s);
			if (s == "") break;
			stringstream sin(s);
			for (int j = 1; j <= n; j++)
				sin >> v[m][j];
			m++;
		}
		memset(out, 0, sizeof out);
		while (true){
			memset(count, 0, sizeof count);
			for (int i = 0; i < m; i++){
				int j = 1; while (out[v[i][j]]) j++;
				count[v[i][j]]++;
			}

			int w = 0, l = m+1;
			for (int j = 1; j <= n; j++){
				if (!out[j]){
					w = max(w, count[j]);
					l = min(l, count[j]);
				}
			}
			if (2*w > m){
				int index = 0;
				for (int j = 1; j <= n; j++)
					if (count[j] == w) index = j;
				cout << conv[index] << endl;
				break;
			}
			int qt = 0;
			for (int j = 1; j <= n; j++)
				qt += count[j] == w;

			if (qt*w == m){
				for (int j = 1; j <= n; j++)
					if (count[j] == w)
						cout << conv[j] << endl;
				break;
			}
			for (int j = 1; j <= n; j++)
				out[j] |= (count[j] == l);

		}
		if (t != 0) cout << endl;
	}
	return 0;
}

