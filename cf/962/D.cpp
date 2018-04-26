#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

typedef long long int lli;
typedef pair<lli, lli> pii;

const int MAXN = 150010;

int main(){ _
	int n, v;
	cin >> n;
	priority_queue<pii, vector<pii>, greater<pii>> h;
	for (int i = 0; i < n; i++){
		cin >> v;
		h.push(pii(v, i));
	}
	set<pii> s;
	while (h.size() >= 2){
		auto l = h.top(); h.pop();
		auto r = h.top(); h.pop();
		if (l.first == r.first){
			h.push(pii(2LL*l.first, r.second));
			continue;
		}
		h.push(l); h.push(r);
		while (!h.empty()){
			auto it = h.top();
			if (it.first != l.first) break;
			s.insert(pii(it.second, it.first));
			h.pop();
		}
	}
	while (!h.empty()){
		auto it = h.top();
		s.insert(pii(it.second, it.first));
		h.pop();
	}
	cout << s.size() << endl;
	for (auto it : s)
		cout << it.second << " ";
	cout << endl;
	return 0;
}
