#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;

#define MAXV 110

int n, m;
pii e[10010];

vi g[MAXV];

bool visited[MAXV];
int out;
int dest;
int dfs(int v){
	visited[v] = true;
	int ans = 1;
	for (int ie : g[v]){
		if (ie == out) continue;
		int w = e[ie].second;
		if (visited[w]) continue;
		ans += dfs(w);
	}
	return ans;
}

int main(){ _
	string s[MAXV];
	cin >> n >> m;
	while (true){
		if (n == 0 && m == 0) break;

		map<string, int> conv;
		for (int i = 1; i <= n; i++){
			cin >> s[i];
			conv[s[i]] = i;
			g[i].resize(0);
		}
		for (int i = 1; i <= m; i++){
			string l, r;
			cin >> l >> r;
			int u = conv[l], v = conv[r];
			e[i] = pii(v, u);
			g[v].push_back(i);
		}
		bool one = false;
		for (int i = 1; i <= m; i++){
			out = i;
			memset(visited, 0, sizeof visited);
			int qt = dfs(1);
			if (qt < n){
				one = true;
				cout << s[e[i].second] << " " << s[e[i].first] << '\n';
			}
		}
		if (!one) cout << "Nenhuma" << '\n';
		cin >> n >> m;
		if (n != 0 || m != 0)
			cout << '\n';
	}
	return 0;
}

