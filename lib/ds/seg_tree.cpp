#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int MAX = 5e4+10;

const int INF = 0x3f3f3f3f;

typedef vector<int> vi;

//Potentiometer UVA
//Interval Product LiveArchive
//LCA SPOJ
template<typename T, typename OP> struct seg_tree{
	OP op;
	T t[10*MAX];
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
	seg_tree(){}
};

template<typename T> struct min_el{
	T operator()(const T& l){
		return l;
	}
	T operator()(const T& l, const T& r){
		return min(l, r);
	}
};
