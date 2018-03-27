lli pow(lli b, lli e, lli mod){
	if (e%2 == 1)
		return multmod(b, pow(b, e-1, mod), mod);
	if (e == 0)
		return 1;
	lli tmp = pow(b, e/2, mod);
	return multmod(tmp, tmp, mod);
}
