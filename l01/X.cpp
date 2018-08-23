#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int value(string s){
	int n = 0;
	for (char c : s){
		n *= 2;
		n += c == '1';
	}
	return n;
}

int gcd(int a, int b){
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main(){ _
	int n, l, r;
	cin >> n;
	for (int i = 1; i <= n; i++){
		string s;
		cin >> s;
		l = value(s);
		cin >> s;
		r = value(s);
		cout << "Pair #" << i << ": ";
		if (gcd(l, r) == 1){
			cout << "Love is not all you need!" << endl;
		}
		else{
			cout << "All you need is love!" << endl;
		}
	}
	return 0;
}
