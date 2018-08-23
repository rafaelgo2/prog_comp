#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAX = 2e5 + 10;

//Potentiometer
template<typename T, typename OP> struct seg_tree{
	OP op;
	T t[4*MAX];
	int n;
	int L, R;
	T *v;
	T build(int l, int r, int i){
		if (l == r) return t[i] = op(v[l]);
		int m = (l+r)/2;
		T lb = build(l, m, 2*i+1);
		T rb = build(m+1, r, 2*i+2);
		return t[i] = op(lb, rb);
	}
	T query(int l, int r, int i){
		if (L <= l && r <= R) return t[i];
		int m = (l+r)/2;
		if (m >= R) return query(l, m, 2*i+1);
		if (m < L) return query(m+1, r, 2*i+2);
		return op(query(l, m, 2*i+1), query(m+1, r, 2*i+2));
	}
	T query(int L_, int R_){
		L = L_;
		R = R_;
		return query(0, n-1, 0);
	}
	T update(int l, int r, int i, int k){
		if (l == r) return t[i] = op(v[k]);
		int m = (l+r)/2;
		if (m >= k) return t[i] = op(t[2*i+2], update(l, m, 2*i+1, k));
		if (m < k) return t[i] = op(t[2*i+1], update(m+1, r, 2*i+2, k));
		return t[i] = op(update(l, m, 2*i+1, k), update(m+1, r, 2*i+2, k));
	}
	T update(int k){
		return update(0, n-1, 0, k);
	}
	seg_tree(T* v_, int n_){
		v = v_;
		n = n_;
		build(0, n-1, 0);
	}
};

template<typename T> struct max_el{
	T inline operator()(const T& l){
		return l;
	}
	T inline operator()(const T& l, const T& r){
		return max(l, r);
	}
};

template<typename T> struct min_el{
	T operator()(const T& l){
		return l;
	}
	T operator()(const T& l, const T& r){
		return min(l, r);
	}
};

template<typename T> struct prod{
	T operator()(const T& l){
		return l;
	}
	T operator()(const T& l, const T& r){
		return l*r;
	}
};

int v[MAX];

int fix(int i){
	if (i > 0) return 1;
	if (i < 0) return -1;
	return 0;
}

int main(){ _
	int n, m;
	while (cin >> n >> m){
		v[0] = 0;
		for (int i = 1; i <= n; i++){
			cin >> v[i];
			v[i] = fix(v[i]);
		}
		seg_tree<int, prod<int>> st(v, n+1);
		string op;
		int x, y;
		for (int i = 1; i <= m; i++){
			cin >> op >> x >> y;
			if (op == "C"){
				int k = fix(y);
				v[x] = k;
				st.update(x);
			}
			if (op == "P"){
				int k = st.query(x, y);
				if (k < 0) cout << '-';
				if (k == 0) cout << '0';
				if (k > 0) cout << '+';
			}
		}
		cout << endl;
		
	}
	return 0;
}

