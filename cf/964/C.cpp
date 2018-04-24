#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

typedef long long int lli;

lli MOD = 1000000000 + 9;

lli inv(lli a, lli b){
	static vector<lli> u(3), m(3), d(3);
	u[0] = a; u[1] = 1; u[2] = 0;
	m[0] = b; m[1] = 0; m[2] = 1;
	while (u[0]%m[0] != 0){
		lli n = u[0]/m[0];
		for (int i = 0; i < 3; i++)
			d[i] = u[i] - n*m[i];
		u = m;
		m = d;
	}
	return (m[1]+b) % b;
}

lli pow(lli b, lli e, lli mod){
	if (e%2 == 1)
		return (b*pow(b, e-1, mod))%mod;
	if (e == 0) return 1;
	lli tmp = pow(b, e/2, mod);
	return (tmp*tmp)%mod;
}

lli sum_pg(lli s, lli r, lli qt){
	if (r == 1){
		return (s*qt) % MOD;
	}
	lli aux = pow(r, qt, MOD);
	lli num = (MOD + 1 - aux) % MOD;
	lli den = inv((MOD + 1 - r)%MOD, MOD);
	return (((s*num)%MOD)*den) % MOD;
}

int main(){ _
	int n, k;
	lli s[100010];
	lli a, b;
	cin >> n >> a >> b >> k;
	lli inva = inv(a, MOD);
	lli invb = inv(b, MOD);
	char c;
	for (int i = 0; i < k; i++){
		cin >> c;
		if (c == '+') s[i] = 1;
		else s[i] = MOD-1LL;
	}
	lli tmp = 0;
	lli tmpa = pow(a, n, MOD);
	lli tmpb = 1;
	for (int i = 0; i < k; i++){
		lli mult = (tmpa*tmpb) % MOD;
		lli inc = (s[i]*mult) % MOD;
		tmp = (tmp + inc) % MOD;
		tmpa = (tmpa * inva) % MOD;
		tmpb = (tmpb * b) % MOD;
	}
	int qt = (n+1)/k;
	lli aux = (inva*b)%MOD;
	lli r = pow(aux, k, MOD);
	lli sc = tmp;
	lli ans = sum_pg(sc, r, qt);
	cout << ans << endl;
	return 0;
}
