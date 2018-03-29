#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

typedef pair<int, int> pii;

bool has_square(pii l, pii r, vector< vector< set<pii> > > &t){
	bool ans = true;
	for (int i = l.first; i <= r.first-1; i++)
		ans &= t[i][l.second].count(pii(i+1, l.second)) != 0;
	
	for (int i = l.first; i <= r.first-1; i++)
		ans &= t[i][r.second].count(pii(i+1, r.second)) != 0;

	for (int j = l.second; j <= r.second-1; j++)
		ans &= t[l.first][j].count(pii(l.first, j+1)) != 0;

	for (int j = l.second; j <= r.second-1; j++)
		ans &= t[r.first][j].count(pii(r.first, j+1)) != 0;

	return ans;
}

int main(){ _
	int n, m, A = 1;
	cin >> n >> m;
	while (true){
		vector< vector< set<pii> > > v(n, vector< set<pii> >(n));
		char c;
		int i, j;
		for (int l = 0; l < m; l++){
			cin >> c >> i >> j;
			i--; j--;

			if (c == 'H'){
				v[i][j].insert(pii(i, j+1));
			}
			else{
				v[j][i].insert(pii(j+1, i));
			}
		}

		map<int, int> counter;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				for(int k = 1; k <= (n-max(i, j)-1); k++){
					if (has_square(pii(i, j), pii(i+k, j+k), v)){
						counter[k]++;
					}
				}
			}
		}
		cout << "Problem #" << A++ << endl;
		cout << endl;
		if (counter.size() != 0){
			for (pii p : counter)
				cout << p.second << " square (s) of size " << p.first << endl;
		}
		else{
			cout << "No completed squares can be found." << endl;
		}
		
		if (cin >> n >> m){
			cout << endl;
			cout << "**********************************" << endl;
			cout << endl;
		}
		else
			break;
	}
	return 0;
}
