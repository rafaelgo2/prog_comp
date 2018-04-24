lli sum_pg(lli s, lli r, lli qt){
	if (r == 1){
		return (s*qt) % MOD;
	}
	lli aux = pow(r, qt, MOD);
	lli num = (MOD + 1 - aux) % MOD;
	lli den = inv((MOD + 1 - r)%MOD, MOD);
	return (((s*num)%MOD)*den) % MOD;
}

