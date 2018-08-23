#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

typedef vector<char> vc;
typedef set<char> sc;
typedef pair<char, char> pcc;

string cat_all(vector<char> &v){
	string s = "";
	s += v.front();
	for (int i = 1; i < v.size(); i++){
		s += ",";
		s += v[i];
	}
	return s;
}

string space(int q){
	string s = "";
	while (q--) s+= " ";
	return s;
}

void func(vector<char> v, int x, int q){
	if ((v.size()-1) == x){
		cout << space(q) << "writeln(" << cat_all(v) << ")" << endl;
		return;	
	}
	vector<char> aux = v;
	int i = x+1;
	while (true){
		cout << space(q);
		if (i == x+1)
			cout << "if " << v[i-1] << " < " << v[i] << " then" << endl;
		else if (i > 0)
			cout << "else if " << v[i-1] << " < " << v[i] << " then" << endl;
		else
			cout << "else" << endl;
		func(v, x+1, q+2);
		if (i == 0) break;
		swap(v[i], v[i-1]);
		i--;
	}
}

int main(){ _
	int k;
	cin >> k;
	while (k--){
		int n;
		cin >> n;
		vector<char> v;
		for (int i = 0; i < n; i++)	v.push_back('a'+i);
		cout << "program sort(input,output);" << endl
			 << "var" << endl
			 << cat_all(v) << " : integer;" << endl
			 << "begin" << endl
			 << space(2) << "readln(" << cat_all(v) << ");" << endl;	
		func(v, 0, 2);
		cout << "end." << endl;
		if (k != 0) cout << endl;
	}

	return 0;
}

