#define MAX_ITEMS 10000
struct union_find{
	int id[MAX_ITEMS];
	void init(int n){
		for (int i = 0; i <= n; i++)
			id[i] = i;
	}
	int get_id(int i){
		if (id[i] == i)	return i;
		return id[i] = get_id(id[i]);
	}
	void join(int l, int r){
		int id_l = get_id(l);
		int id_r = get_id(r);
		id[id_l] = id_r;
	}
};
