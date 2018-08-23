#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

typedef long long int lli;

const int IDENTITY = (12);

lli MOD;

template<typename T> struct matrix {
	vector<vector<T>> in;
	int n, m;
	matrix(int n, int m, int op = 0):n(n), m(m), in(n, vector<T>(m, 0)){
		if (op == IDENTITY) for (int i = 0; i < n; i++)	in[i][i] = 1;
	}
	matrix(initializer_list<initializer_list<T>> c):
		n(c.size()), m((*c.begin()).size()){
		in = vector<vector<T>>(n, vector<T>(m, 0));
		int i, j;
		i = 0;
		for (auto &it : c){
			j = 0;
			for (auto &jt : it){
				in[i][j] = jt;
				j++;
			}
			i++;
		}
	}
	T &operator()(int i, int j){
		return in[i][j];
	}
	matrix<T> operator*(matrix<T> &r){
		matrix<T> &l = *this;
		int row = l.n;
		int col = r.m;
		int K = l.m;
		matrix<T> m(row, col, 0);
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				for (int k = 0; k < K; k++)
					m(i, j) = (m(i, j) + l(i, k)*r(k, j) % MOD) % MOD;
		return m;
	}
	matrix<T> operator^(lli e){
		matrix<T> &m = (*this);
		if (e == 0) return matrix(m.n, m.n, IDENTITY);
		if (e == 1) return m;
		if (e == 2) return m*m;
		auto m_ = m^(e/2);
		m_ = m_*m_;
		if (e%2 == 1) m_ = m_ * m;
		return m_;
	}
};

template<typename T>ostream &operator<<(ostream &out, matrix<T> &v){
	for (int i = 0; i < v.n; i++){
		for (int j = 0; j < v.m; j++) out << v(i, j) << " ";
		out << endl;
	}
	return out;
}



int main(){ _
	lli n, p, g;
	MOD = 1000000LL;
	while (cin >> n >> p >> g){
		n /= 5LL;
		p %= MOD;
		g %= MOD;
		matrix<lli> trans = {
			{0, g},
			{1, p}
		};
		matrix<lli> transp = trans^n;
		cout << setfill('0') << setw(6) << transp(1, 1)%MOD << endl;
	}
	return 0;
}

