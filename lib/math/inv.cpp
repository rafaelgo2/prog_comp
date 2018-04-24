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

