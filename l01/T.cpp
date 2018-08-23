#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

typedef vector<int> vi;

int dfs(vector<vi> &graph, int v, vector<bool> &visited){
	if (visited[v]) return 0;
	int ans = 1;
	visited[v] = true;
	for (int n : graph[v])
		ans += dfs(graph, n, visited);
	return ans;
}

bool is_eulerian_dir(vector<vi> &graph){
	set<int> s;
	for (int i = 0; i < 30; i++){
		if (graph[i].size() != 0) s.insert(i);
		s.insert(graph[i].begin(), graph[i].end());
	}
	int count = s.size();

	vector<int> delta(30);
	for (int i = 0; i < 30; i++){
		delta[i] += graph[i].size();
		for (int n : graph[i]) delta[n]--;
	}

	int init = 0;	
	for (int i = 0; i < 30; i++)
		if (delta[i] > delta[init]) init = i;

	vector<bool> visited(graph.size(), false);
	if (dfs(graph, init, visited) != count) return 0;

	sort(delta.begin(), delta.end());

	bool ans = (((delta.front() + delta.back()) == 0) && abs(delta.front()) <= 1);
	for (int i = 1; i < 29; i++)
		ans &= delta[i] == 0;

	return ans;
}

int main(){ _
	int n;
	cin >> n;
	while (n--){
		vector<vi> graph(30);
		int m;
		cin >> m;
		string s;
		while (m--){
			cin >> s;
			graph[s.front() - 'a'].push_back(s.back() - 'a');
		}

		if (is_eulerian_dir(graph))
			cout << "Ordering is possible." << endl;
		else
			cout << "The door cannot be opened." << endl;
	}
	return 0;
}
