#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int F, P, E, A;
int e[5010][30];
int a[5010][30];


int memo[5010][30];

int get(int p, int f){
	if (p > P) return 0;
	if (memo[p][f] == -1){
		int ans = e[p][f]*a[p][f] + get(p+1, f);
		for (int i = 1; i <= F; i++){
			int tmp = E*A + e[p][i]*a[p][i] + get(p+1, i);
			ans = min(ans, tmp);
		}
		memo[p][f] = ans;
	}
	return memo[p][f];
	
}


int main(){ _
	while (true){
		cin >> F >> P >> E >> A;
		if ((F+P+E+A) == 0) break;
		for (int i = 1; i <= P; i++)
			for (int j = 1; j <= F; j++)
				cin >> e[i][j] >> a[i][j];
		memset(memo, -1, sizeof memo);
		cout << get(1, 1) << endl;
	}
	return 0;
}

