#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){ _
	int x1, x2, y1, y2, r1, r2;
	while (cin >> r1 >> x1 >> y1 >> r2 >> x2 >> y2){
		int dx = x1-x2;
		int dy = y1-y2;
		double dist = hypot(dx, dy);
		if (dist+r2 <= r1) cout << "RICO" << endl;
		else cout << "MORTO" << endl;
	}
	return 0;
}

