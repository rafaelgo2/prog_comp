#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int a[110];
int b[110];
int c[110];

const int INF = 0x3f3f3f3f;

int n;

int memo[101][8][6][5];
int memop[101][8][6][5];

int get(int i, int A, int B, int C){
	if (A < 0) return -INF;
	if (B < 0) return -INF;
	if (C < 0) return -INF;
	if (A+B+C == 0) return 0;
	if (i < 0) return -INF;
	if (memo[i][A][B][C] == -1){
		int ans = get(i-1, A, B, C);
		int op = 0;
		{
			int inc = round(0.8*a[i] + 0.0*b[i] + 0.2*c[i]); 
			int opA = get(i-1, A-1, B, C) + inc;
			if (opA > ans){
				op = 1;
				ans = opA;
			}
		}
		{
			int inc = round(0.1*a[i] + 0.7*b[i] + 0.2*c[i]); 
			int opB = get(i-1, A, B-1, C) + inc;
			if (opB > ans){
				op = 2;
				ans = opB;
			}
		}
		{
			int inc = round(0.4*a[i] + 0.4*b[i] + 0.2*c[i]); 
			int opC = get(i-1, A, B, C-1) + inc;
			if (opC > ans){
				op = 3;
				ans = opC;
			}
		}
		memo[i][A][B][C] = ans;
		memop[i][A][B][C] = op;
	}
	return memo[i][A][B][C];
}

int main(){ _
	int k = 1;
	while (true){
		cin >> n;
		if (n == 0) break;
		if (k != 1) cout << endl;
		memset(memo, -1, sizeof memo);
		memset(memop, -1, sizeof memop);
		for (int i = 0; i < n; i++)
			cin >> a[i] >> b[i] >> c[i];
		int A, B, C;
		cin >> A >> B >> C;
		int ans = get(n-1, A, B, C);
		int i = n-1;
		vector<int> v[4];
		while (A+B+C != 0){
			int op = memop[i][A][B][C];
			if (op != 0) v[op].push_back(i);
			i--;
			if (op == 1) A--;
			if (op == 2) B--;
			if (op == 3) C--;
		}
		string out[4] = {"", "Batsmen :", "Bowlers :", "All-rounders :"};
		cout << "Team #" << k++ << endl; 
		cout << "Maximum Effective Score = " << ans << endl;
		for (int i = 1; i <= 3; i++){
			cout << out[i];
			for (int j : v[i]) cout << " " << j+1;
			cout << endl;
		}
	}
	return 0;
}

