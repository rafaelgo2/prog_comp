#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

typedef long long int lli;

vector<lli> primes;
void sieve(lli n){
	primes.resize(0);
	vector<bool> v(n+1, false);
	for (lli i = 2LL; i <= n; i++){
		if (v[i]) continue;
		for (lli j = i+i; j <= n; j += i)
			v[j] = true;
		primes.push_back(i);
	}
}

lli get(lli x){
	lli ans = 0;
	for (lli i : primes){
		if ((i*i) > x){
			//cout << i << " " << i*i << " " << x << endl;	
			break;
		}
		lli tmp = i*i;
		while (tmp <= x){
			ans++;
			tmp *= i;
		}
	}
	return ans;
}

int main(){ _
	sieve(1000001);
//cout << primes[primes.size() - 1] << endl;
//cout << primes[primes.size() - 2] << endl;
//cout << primes[primes.size() - 3] << endl;
	int n;
	cin >> n;
	lli l, r;
	while (n--){
		cin >> l >> r;
		l--;
		cout << get(r) - get(l) << endl;
	}
	return 0;
}

