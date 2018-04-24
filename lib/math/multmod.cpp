// returns (a*b)%c
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
