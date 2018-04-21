#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

#define MAXV 510

int g[MAXV][MAXV];
int l[MAXV][MAXV];
int r[MAXV][MAXV];
int ans[MAXV][MAXV];

void multiply(int l[MAXV][MAXV], int r[MAXV][MAXV], int ans[MAXV][MAXV], int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            ans[i][j] = 0;
            for (int k = 0; k < n; k++)
                ans[i][j] += l[i][k]*r[k][j];
        }
    }
}
typedef long long int lli;
lli save[MAXV];

int main(){ _
    int n, v;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];
    for (int i = 0; i < n; i++){
        cin >> v;
        v--;
        r[v][i] = 1;
        l[i][v] = 1;
    }
    multiply(l, g, ans, n);
    multiply(ans, r, g, n);
    for (int k = n-1; k >= 0; k--){
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
        lli sum = 0;
        for (int i = k; i < n; i++)
            for (int j = k; j < n; j++)
                sum += g[i][j];
		save[k] = sum;
    }
	cout << save[0];
	for (int i = 1; i < n; i++)
		cout << " " << save[i];
	cout << endl;
    return 0;
}

