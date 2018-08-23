#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int n, m;
vector< vector<char> > t;
vector< vector<int> > c;

typedef pair<int, int> pii;
#define x first
#define y second

pii rotate(char c, pii ori){
	if (c == 'L'){
		return pii(
			ori.y,
			-ori.x
		);
	}
	else{
		return pii(
			-ori.y,
			ori.x
		);
	}
}

pii operator+(pii l, pii r){
	return pii(l.x + r.x, l.y + r.y);
}

bool valid(pii p){
	if (p.x < 0 || p.x >= m) return false;
	if (p.y < 0 || p.y >= n) return false;
	if (t[p.y][p.x] == '1')	return false;
	return true;
}


int main(){ _
	while (true){
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		t = vector< vector<char> >(n, vector<char>(m));
		c = vector< vector<int> >(n, vector<int>(m, 0));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> t[i][j];

		char tmp;
		pii cur(0, n-1), ori(1, 0);
		do{
			c[cur.y][cur.x]++;
			ori = rotate('R', ori);
			while (true){
				if (valid(cur+ori))	break;
				ori = rotate('L', ori);
			}
			cur = cur + ori;

		}while (cur != pii(0, n-1));

		map<int, int> counter;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				counter[c[i][j]]++;
				if (t[i][j] == '1') 
					counter[c[i][j]]--;
			}
		}
		for (int i = 0; i < 5; i++)
			cout << setw(3) << counter[i];
		cout << endl;
	}
	return 0;
}
