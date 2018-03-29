#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

void floyd(int graph[30][30]){
	for (int i = 0; i < 30; i++)
		for (int j = 0; j < 30; j++)
			for (int k = 0; k < 30; k++)
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
}

#define INF 99999999

int main(){ _
	int n;
	while (true){
		cin >> n;
		if (n == 0) break;

		int graph[2][30][30];
		for (int k = 0; k < 2; k++){
			for (int i = 0; i < 30; i++){
				for (int j = 0; j < 30; j++) graph[k][i][j] = INF;
				graph[k][i][i] = 0;
			}
		}

		char age, dir, from, to;
		int w;
		while (n--){
			cin >> age >> dir >> from >> to >> w;
			from -= 'A'; to -= 'A';
			int i = (age == 'Y') ? (0) : 1;
			graph[i][from][to] = min(graph[i][from][to], w);
			if (dir == 'B') graph[i][to][from] = min(graph[i][to][from], w);
		}
		char y, o;
		cin >> y >> o;
		y -= 'A'; o -= 'A';
		floyd(graph[0]);
		floyd(graph[1]);

		set<int> ans;
		ans.insert(0);
		int dist = graph[0][y][*ans.begin()] + graph[1][o][*ans.begin()];
		for (int i = 0; i < 30; i++){
			int dist_ = graph[0][y][i] + graph[1][o][i];
			if (dist_ == dist)
				ans.insert(i);
			if (dist_ < dist){
				ans = set<int>();
				ans.insert(i);
				dist = dist_;
			}
		}

		if (dist >= INF)
			cout << "You will never meet." << endl;
		else{
			cout << dist;
			for (int i : ans)
				cout << " " << char('A' + i);
			cout << endl;
		}
	}
	return 0;
}
