#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

// clever naming patters
//https://www.codepit.io/#/problems/5369c2bbf6fa9de49e5c5b4e/view?index=1


typedef vector<int> vi;

bool augment(int v, vector<vi> &graph, vi &visited, vi &match){
	if (visited[v]) return false;
	visited[v] = true;
	for (int w : graph[v]){
		if (match[w] == -1 || augment(match[w], graph, visited, match)){
			match[w] = v;
			return true;
		}
	}
	return false;
}

void get_match(vector<vi> &graph, vi &match){//O(v*e)
	fill(match.begin(), match.end(), -1);
	vi visited(graph.size(), 0);
	bool cont = true;
	while(cont){
		cont = false;
		for (int i = 0; i < graph.size(); i++){
			fill(visited.begin(), visited.end(), false);
			cont |= augment(i, graph, visited, match);
		}
	};
}

void fixS(string &s){
	s[0] = toupper(s[0]);
	for (int i = 1; i < s.size(); i++)
		s[i] = tolower(s[i]);
}

int main(){
	int t;
	cin >> t;
	for (int T = 1; T <= t; T++){
		int n;
		cin >> n;
		vector<map<char, string> > memo(n);
		vector<vi> graph(n);
		for (int i = 0; i < n; i++){
			int k;
			cin >> k;
			for (int j = 0; j < k; j++){
				string s;
				cin >> s;
				fixS(s);
				memo[i][s[0]] = s;
				graph[i].push_back(s[0] - 'A');
			}
		}
		vector<int> match(30);
		get_match(graph, match);
		cout << "Case #" << T << ":" << endl;
		for (int i = 0; i < n; i++){
			cout << memo[match[i]]['A'+i] << endl;
		}
	}
	return 0;
}
