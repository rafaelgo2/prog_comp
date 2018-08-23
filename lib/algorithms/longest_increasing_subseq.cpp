template<typename T> vector<T> lis(vector<T> &v){
	vector<T> ans;
	for (T t : v){
		auto it = upper_bound(ans.begin(), ans.end(), t); //apenas maior
		//auto it = lower_bound(ans.rbegin(), ans.rend(), t); //maior igual
		if (it == ans.end()) ans.push_back(t);
		else *it = t;
	}
	return ans;
}
