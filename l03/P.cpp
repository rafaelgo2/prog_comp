#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

typedef pair<int, int> pii;

int gcd(int a, int b){
	if (b == 0)
		return a;
	return gcd(b, a%b);
}


int dist(pii &l, pii &r){
	int dX = abs(l.first - r.first);
	int dY = abs(l.second - r.second);
	return gcd(dX, dY) - 1;
}

int main(){ _
	int t;
	cin >> t;
	while (t--){
		int n, k;
		cin >> n >> k;
		pii v[1010];
		for (int i = 0; i < n; i++)
			cin >> v[i].first >> v[i].second;
		set<int> visited;
		priority_queue<pii, vector<pii>, greater<pii> > heap;
		heap.push(pii(0, 0));
		int ans = 0;
		while(!heap.empty()){
			pii pt = heap.top();
			heap.pop();
			if (visited.count(pt.second))
				continue;
			ans += pt.first;
			visited.insert(pt.second);
			for (int i = 0; i < n; i++)
				heap.push(pii(dist(v[i], v[pt.second]), i));
		}
		cout << ans*k << endl;
	}	
	return 0;
}
