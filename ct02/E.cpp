#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

typedef pair<int, int> pii;

int main(){ _
	int n, m;
	vector<pii> occ;
	vector<string> emot(100);
	string text;
	while (true){
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;
		for (int i = 0; i < n; i++)
			cin >> emot[i];
		cin.ignore();
		int qt = 0;
		for (int i = 0; i < m; i++){
			occ.resize(0);
			getline(cin, text);
			for (int j = 0; j < n; j++){
				int cur = -1;
				while ((cur = text.find(emot[j], cur+1)) != string::npos)
					occ.push_back(pii(cur, cur+emot[j].size()-1));
				
			}
			if (occ.size() > 0){
				qt++;
				sort(occ.begin(), occ.end());
				int R = occ.back().second + 1;
				for (int i = 0; i < occ.size(); i++){
					if (occ[i].first > R){
						qt++;
						R = occ[i].second;
					}
					R = min(R, occ[i].second);
				}
			}
		}
		cout << qt << endl;
	}
	return 0;
}
