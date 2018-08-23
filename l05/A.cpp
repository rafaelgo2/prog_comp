#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int MAX  = 1e6;

int parent(int i){
	return i - (i & -i);
}
int next(int i){
	return i + (i & -i);
}

//12086 - Potentiometers: AC
template<typename T> struct bit{
	int n;
	T t[MAX];
	T get(int i){ //O(log(n))
		int it = i+1;
		T ans = 0; 
		while (it > 0){
			ans += t[it];
			it = parent(it);
		}
		return ans;
	}
	void inc(int i, T v){ //O(log(n))
		int it = i+1;
		while (it <= n){
			t[it] += v;
			it = next(it);
		}
	}
	T sum_range(int l, int r){ //O(log(n))
		return get(r) - get(l-1);
	}
	void init(int n_, T *v = NULL){ //O(n)
		n = n_;
		t[0] = 0;
		if (v == NULL){
			for (int i = 1; i <= n; i++) t[i] = 0;
			return;
		}
		for (int i = 1; i <= n; i++)
			t[i] = v[i-1];
		for  (int i = 0; i <= n; i++){
			int j = next(i);
			if (j > n) continue;
			t[j] += t[i];
		}
	}
};

template <typename T> struct bit_seg{
	bit<T> b1;
	bit<T> b2;
	int n;
	void inc(int l, int r, T v){ //O(log(n))
		b1.inc(l, v);
		b1.inc(r+1, -v);

		b2.inc(l, v*(l-1));
		b2.inc(r+1, -v*r);
	}
	T get(int i){ //O(log(n))
		return (b1.get(i)*i) - b2.get(i);
	}
	T sum_range(int l, int r){//O(log(n))
		return get(r) - get(l-1);
	}
	void init(int n_, T *v = NULL){ //O(nlog(n))
		n = n_;
		b1.init(n, NULL);
		b2.init(n, NULL);
		if (v == NULL) return;
		for (int i = 0; i < n; i++)
			inc(i, i, v[i]);
	}
};

int v[MAX+10];

int main(){ _
	bit<int> b;
	int n;
	cin >> n;
	b.init(n+1);
	int t;
	cin >> t;
	cout << t;
	b.inc(t, 1);
	for (int i = 1; i < n; i++){
		cin >> t;
		cout << " " << t - b.sum_range(0, t);
		b.inc(t, 1);
	}
	cout << endl;
	return 0;
}

