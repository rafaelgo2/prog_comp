#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

typedef long long int lli;

typedef vector<vector<lli>> matrix;

ostream& operator<<(ostream &out, matrix m){
	for (int i = 0; i < m.size(); i++){
		for (int j = 0; j < m[i].size(); j++)
			out << m[i][j] << " ";
		out << endl;
	}
	return out;
}

matrix make_m(int n, int m, lli v = 0){
	return matrix(n, vector<lli>(m, v));
}

matrix identity(int n){
	matrix m = make_m(n, n);
	for (int i = 0; i < n; i++)
		m[i][i] = 1;
	return m;
}

void fix(matrix &m, lli MOD){
	for (int i = 0; i < m.size(); i++)
		for (int j = 0; j < m[i].size(); j++)
			m[i][j] %= MOD;
}

matrix mult(matrix l, matrix r, lli MOD){
	int row = l.size();
	int col = r[0].size();
	int K = l[0].size();
	matrix m = make_m(row, col, 0);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			for (int k = 0; k < K; k++)
				m[i][j] = (m[i][j] + l[i][k]*r[k][j]%MOD)%MOD;
	fix(m, MOD);
	return m;
}

matrix pow(matrix m, lli e, lli MOD){
	fix(m, MOD);
	if (e == 0) return identity(m.size());
	if (e == 1) return m;
	if (e == 2) return mult(m, m, MOD);
	matrix m_ = pow(m, e/2, MOD);
	m_ = mult(m_, m_, MOD);
	if (e%2 == 1) m_ = mult(m_, m, MOD);
	return m_;
}


int main(){ _
	int n, m;
	int it = 1;
	while (true){
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		cout << "Case " << it++ << ": " << n << " " << m << " ";
		matrix v = make_m(3, 1);
		v[0][0] = 1;
		v[1][0] = 1;
		v[2][0] = 1;
		matrix trans = make_m(3, 3);
		trans[0][0] = 1; 
		trans[1][0] = 1;
		trans[2][0] = 0;
		trans[0][1] = 1;
		trans[1][1] = 0;
		trans[2][1] = 0;
		trans[0][2] = 1;
		trans[1][2] = 0;
		trans[2][2] = 1;
		trans = pow(trans, n, m);
		matrix r = mult(trans, v, m);
		cout << r[1][0] << endl;
	}
	return 0;
}

