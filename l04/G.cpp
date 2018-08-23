#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int INF = (0x3f3f3f3f);

int mat[1010][1010];
int n;

int MEMT[1010][1010];
bool flagT[1010][1010];
int get_T(int i, int j){
	if (i < 0 || i >= n) return 0;
	if (j < 0 || j >= n) return 0;
	if (!flagT[i][j]){
		int ans = mat[i][j];
		ans += get_T(i-1, j);
		ans += get_T(i-1, j-1);
		ans -= get_T(i-2, j-1);
		flagT[i][j] = true;
		MEMT[i][j] = ans;
	}
	return MEMT[i][j];
}

int get_D(int i, int j){
	return get_T(i, j) - get_T(i-1, j-1);
}

int get_ANS(int i, int j);

int MEMINC[1010][1010];
bool flagINC[1010][1010];

int get_inc(int i, int j){
	if (i < 0 || i >= n) return -INF;
	if (j < 0 || j >= n) return -INF;
	if (!flagINC[i][j]){
		int inc = max(get_ANS(i, j-1), get_inc(i+1, j));
		MEMINC[i][j] = inc;
		flagINC[i][j] = true;
	}
	return MEMINC[i][j];
}

int MEMANS[1010][1010];
bool flagANS[1010][1010];
int get_ANS(int i, int j){
	if (i < 0 || i >= n) return 0;
	if (j < 0 || j >= n) return 0;
	if (!flagANS[i][j]){
		int ans = get_D(i, j);
		int inc = get_ANS(i-1, j-1);
		int t = get_inc(i, j);
		ans += max(inc, t);
		flagANS[i][j] = true;
		MEMANS[i][j] = ans;
	}
	return MEMANS[i][j];
}


int main(){ _
	while (true){
		cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; i++)
			for (int j = 0; j <= i; j++)
				cin >> mat[i][j];
		int ans = 0;
		memset(flagT, 0, sizeof flagT);
		memset(flagANS, 0, sizeof flagANS);
		memset(flagINC, 0, sizeof flagINC);
		for (int i = 0; i < n; i++){
			for (int j = 0; j <= i; j++){ 
				ans = max(ans, get_T(i, j));
				ans = max(ans, get_ANS(i, j));
			}
		}
		cout << ans << endl;
	}
	return 0;
}


