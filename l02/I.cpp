#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

typedef long long int lli;

lli gcd(lli a, lli b){
	if (b == 0) return a;
	return gcd(b, a%b);
}

lli multmod(lli a, lli b, lli c){
	lli x = 0, y = a % c;
	while (b > 0){
		if (b % 2 == 1)
			x = (x+y) % c;
		y = (2*y) % c;
		b /= 2;
	}
	return x % c;
}

lli pow(lli b, lli e, lli mod){
	if (e%2 == 1)
		return multmod(b, pow(b, e-1, mod), mod);
	if (e == 0)
		return 1;
	lli tmp = pow(b, e/2, mod);
	return multmod(tmp, tmp, mod);
}

lli divisor_of(lli n){ //Polard rho
	if ((n & 1) == 0)
		return 2;
	int i = 0, k = 2;
	lli x = 3, y = 3;
	while (true){
		i++;
		x = (multmod(x, x, n) + n - 1) % n;
		lli d = gcd(abs(y-x), n);
		if (d != 1 && d != n)
			return d;
		if (i == k){
			y = x;
			k *= 2;
		}
	}
}

typedef tuple<lli, lli, lli> tlli;

tlli operator*(lli s,tlli t){
	get<0>(t) *= s;
	get<1>(t) *= s;
	get<2>(t) *= s;
	return t;
}

tlli operator+(tlli l, tlli r){
	get<0>(l) += get<0>(r);
	get<1>(l) += get<1>(r);
	get<2>(l) += get<2>(r);
	return l;
}

lli inv(lli a, lli b){
	tlli u(a, 1, 0);
	tlli m(b, 0, 1);
	tlli d;
	while (get<0>(u) % get<0>(m) != 0){
		lli n = get<0>(u)/get<0>(m);
		d = u + ((-n)*m);
		u = m;
		m = d;
	}
	return (get<1>(m) + b) % b;
}

int main(){ _
	lli n, e, c;
	cin >> n >> e >> c;
	lli p = divisor_of(n);
	lli q = n/p;
	lli d = inv(e, (p-1)*(q-1));
	cout << pow(c, d, n) << endl;
	return 0;
}

