void compress(int *v, int n){
	map<int, int> m;
	for (int i = 0; i < n; i++){
		if (m.find(v[i]) == m.end())
			m[v[i]] = m.size();
		v[i] = m[v[i]];
	}
}

