#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
 
int n, graph[2][2001][2001], visited[2][2001];
 
int bfs(int v, int wich){
	visited[wich][v] = 1;
	int sum = 1;
	for (int i = 1; i <= n; i++)
		if (graph[wich][v][i] && !visited[wich][i])
			sum += bfs(i, wich);
	return sum;
}
 
int main(){ _
	int m, v, w, p;
	cin >> n;
	while (n != 0){
		cin >> m;
		for (int i = 1; i <= 2000; i++)
			for (int j = 1; j <= 2000; j++)
				graph[0][i][j] = graph[1][i][j] = 0;
		while (m--){
			cin >> v >> w >> p;
			graph[0][v][w] = 
			graph[1][w][v] = 1;
			if (p == 2){
				graph[0][w][v] = 
				graph[1][v][w] = 1;
			}
		}
		for (int j = 1; j <= 2000; j++)
			visited[0][j] = visited[1][j] = 0;
		bool satisfy = (bfs(1, 0) == n) && (bfs(1, 1) == n);
		cout << satisfy << endl;
		cin >> n;
	}
		
	return 0;
} 
