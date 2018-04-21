#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
 
int k = 1;
int e, l, graph[101][101], visited[101], a, b;
string ans[2] = {"falha", "normal"};
 
int bfs(int v){
	visited[v] = 1;
	int sum = 1;
	for (int i = 1; i <= e; i++)
		if (graph[v][i] && !visited[i])
			sum += bfs(i);
	return sum;
}
 
 
int main(){ _
	cin >> e >> l;	
	while (e != 0 && l != 0){
		for (int i = 1; i <= e; i++)
			for (int j = 1; j <= e; j++)
				graph[i][j] = 0;
		while (l--){
			cin >> a >> b;
			graph[a][b] = graph[b][a] = 1;
		}
		for (int i = 1; i <= e; i++)
			visited[i] = 0;
		bool valid = bfs(1) == e;
		cout << "Teste " << k++ << endl
			 << ans[valid] << endl; 
		cin >> e >> l;
		if (e != 0 && l != 0)
			cout << endl;
	}	
	return 0;
} 
