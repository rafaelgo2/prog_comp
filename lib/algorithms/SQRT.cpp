const int MAX = 1e6+10;
const int SQ = 70;

int a[MAX];
int occ[MAX];

int counter;
void add(int pos){
	occ[a[pos]]++;
	counter += (occ[a[pos]] == 1);
}
void remove(int pos){
	occ[a[pos]]--;
	counter -= (occ[a[pos]] == 0);
}

scanf("%d", &q);
vector<int> ans(q);
vector<pii> query(q);
vector<pair<pii, int>> s(q);
for (int i = 0; i < q; i++){
	int l, r;
	scanf("%d%d", &l, &r);
	l--; r--;
	query[i] = pii(l, r);
	s[i] = {{l/SQ, r}, i};
}
sort(s.begin(), s.end());
memset(occ, 0, sizeof occ);

int L = 0, R = 0;
add(0)

for (int i = 0; i < q; i++){
	int iq = s[i].second;
	pii q = query[iq];
	while (L < q.first){
		remove(L);
		L++;
	}	
	while (L > q.first){
		L--;
		add(L);
	}
	while (R < q.second){
		R++;
		add(R);
	}
	while (R > q.second){
		remove(R);
		R--;
	}
	ans[iq] = counter;
}
for (int i : ans)
	printf("%d\n", i);

