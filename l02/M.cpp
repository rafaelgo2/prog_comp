#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

typedef long long int lli;

vector<lli> primes;
void sieve(lli n){
	primes.resize(0);
	for (lli i = 2LL; i <= n; i++){
		for (lli p : primes) if (i%p == 0) continue;
		primes.push_back(i);
	}
}

lli phi(lli n){
	if (n <= 2) return 1;
	static vector<lli> div;
	div.resize(0);
	lli tmp = n;
	for (lli i = 2; i*i <= n; i++){
		if (n%i == 0) div.push_back(i);
		while (n%i == 0) n /= i;
	}
	if (n != 1) div.push_back(n);
	for (lli p : div)
		tmp -= tmp/p;
	return tmp;
}

int main(){ _
	lli n;
	while (true){
		cin >> n;
		if (n == 0) break;
		cout << phi(n) << endl;
	}
	return 0;
}

