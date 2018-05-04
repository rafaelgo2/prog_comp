int a[MAX], aux[MAX];
lli merge(int l, int r){
	if (l == r)
		return 0;
	int m = (l+r)/2;
	lli sum =
		merge(l, m) +
		merge(m+1, r);
	int iL = l, iR = m+1, i = l;
	for (int k = l; k <= r; k++)
		aux[k] = a[k];
	while (i <= r){
		if (iL > m){
			a[i++] = aux[iR++];
		}
		else if (iR > r){
			a[i++] = aux[iL++];
		}
		else{
			if (aux[iL] <= aux[iR]){
				a[i++] = aux[iL++];
			}
			else{
				a[i++] = aux[iR++];
				sum += m - iL + 1;
			}
		}
	}
	return sum;
}
