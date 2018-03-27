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
