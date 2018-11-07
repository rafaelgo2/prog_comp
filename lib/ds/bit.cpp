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
	T *t;
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
	bit(){
		t = new T[MAX];
	}
};
