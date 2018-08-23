#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

typedef pair<int, int> pii;

#define x first
#define y second

pii rotate(char c, pii ori){
	if (c == 'L'){
		return pii(
			-ori.y,
			ori.x
		);
	}
	else{
		return pii(
			ori.y,
			-ori.x
		);
	}
}

bool valid(int n, int m, pii curr){
	if (curr.x < 0 || curr.x > n) return false;
	if (curr.y < 0 || curr.y > m) return false;
	return true;
}

pii operator+(pii l, pii r){
	return pii(l.x + r.x, l.y + r.y);
}


int main(){ _
	map<char, pii> conv;
	conv['N'] = pii(0, 1);
	conv['S'] = pii(0, -1);
	conv['E'] = pii(1, 0);
	conv['W'] = pii(-1, 0);
	map<pii, char> back_conv;
	for (pair<char, pii> aux : conv){
		back_conv[aux.second] = aux.first;
	}

	int n, m;
	cin >> n >> m;
	char c;
	int x, y;
	pii curr;
	string ops;
	set<pii> bndry;
	while(cin >> curr.x >> curr.y >> c >> ops){
		pii ori = conv[c];
		bool lost = false;
		for (char c : ops){
			if (c != 'F'){
				ori = rotate(c, ori);
				continue;
			}
			if (valid(n, m, curr+ori)){
				curr = curr + ori;
				continue;
			}

			if (bndry.count(curr))
				continue;
			bndry.insert(curr);
			lost = true;
			break;
		}
		cout << curr.x << " " << curr.y << " " << back_conv[ori];
		if (lost)
			cout << " LOST";
		cout << endl;
		
	}
	return 0;
}
