bool is_p_prime(lli n){ //error prob ~ 4^-t
	if (n <= 4)
		return n == 2 || n == 3;
	
	lli d = n-1;
	while ((d & 1) == 0)
		d >>= 1;

	bool ans = true;
	for (int i = 2; i <= 37; i++){
		lli a = i;
		lli x = pow(a, d, n);
		if (x == 1 || x == n-1)
			continue;
		bool tmp = false;
		while (d != n-1){
			x = pow(x, 2, n);
			d <<= 1;
			tmp |= x == n-1;
			if (x == 1 || x == n-1)
				break;
		}
		ans &= tmp;
	}
	return ans;
}
