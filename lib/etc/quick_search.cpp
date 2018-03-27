#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int find_ith(int i, vector<int> &v){
	if (v.size() == 1) return v[0];
	cout << "occ: " << endl;
	cout << i << endl;
	for (int j : v)
		cout << j << " ";
	cout << endl;
	
	static vector<int> aux;
	static vector<int> l, r;
	l.resize(0); r.resize(0);
	int m = rand() % v.size();
	cout << "rand was: " << v[m] << endl;
	for (int j : v)
		if (j <= v[m]) l.push_back(j);
		else r.push_back(j);

	if (i < l.size())
		return find_ith(i, aux = vector<int>(l));
	else
		return find_ith(i-l.size(), aux = vector<int>(r));
}

int main(){ _
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	int p;
	while (true){
		cin >> p;
		if (p < 0 || p >= n) break;
		random_shuffle(v.begin(), v.end());
		cout << find_ith(p, v) << endl;
	}
	return 0;
}
