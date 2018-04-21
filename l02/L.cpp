#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

#define MAX (500000)

typedef unsigned long long int lli;
vector<lli> primes;

void sieve(lli n){
	vector<bool> v(n+1, false);
	for (lli i = 2LL; i <= n; i++){
		if (v[i]) continue;
		for (lli j = i+i; j <= n; j += i)
			v[j] = true;
		primes.push_back(i);
	}
}

lli func(lli num, lli den, int l){
	if (den > num) return 0;
	if (l >= primes.size()) return 0;
	//cout << num << " " << den << " " << l << endl;
	//string s; cin >> s;
	lli ans = 0;
	for (int p = l; p < primes.size(); p++){
		lli t = primes[p]*primes[p];
		if (t > num) break;
		t *= den;
		if (t > num) break;
		ans += (num/t) - func(num, t, p+1);
		//cout << num << " " << t << " " << l << " " << num/t << endl;
	}
	return ans;
}

int main(){ _
	sieve(MAX);
	//for (int i = 0; i < 2520; i++)
	//	cout << primes[i] << " ";
	//cout << endl;
	int t;
	cin >> t;
	//cout << func(MAX, 1, 0) << endl; return 0;
	//exact(t);
	//cout << func(t, 1, 0) << endl; return 0;
	//for (int i = 1; i <= t; i++)
	//	cout << i << ": " << func(i, 1, 0) << " " << mem[i] << endl;
	//return 0;
	while (t--){
		lli n;
		cin >> n;
		//cout << func(n, 1, 0) << endl; continue;
		lli l = n, r = 40000000000;
		lli ans = r;
		while (l <= r){
			//cout << l << " " << r << endl;
			lli m = (l+r)/2;
			//cout << m << endl;
			lli f = m-func(m, 1, 0);

			if (f == n)	ans = min(ans, m);

			if (f >= n)
				r = m-1;
			else if (f < n)
				l = m+1;

			//string aux; cin >> aux;

		}
		cout << ans << endl;
	}
	return 0;
}

