#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

void get(int n, int &x, int &y){
	x = 0; y = 0;
	int inc = 6, it = 1;
	x = ceil((-3 + sqrt(12*n - 3))/6);
	int rep = 3*(x+1)*(x+1) - 3*(x+1) + 1;;
	int sz = x;
	for (int i = 0; (i < sz) && (n < rep); i++)
		{ y--; rep--;}
	for (int i = 0; (i < sz) && (n < rep); i++)
		{ x--; rep--;}
	for (int i = 0; (i < sz) && (n < rep); i++)
		{ x--; y++; rep--;}
	for (int i = 0; (i < sz) && (n < rep); i++)
		{ y++; rep--;}
	for (int i = 0; (i < sz) && (n < rep); i++)
		{ x++; rep--;}
	for (int i = 0; (i < sz) && (n < rep); i++)
		{ x++, y--; rep--;}
}

typedef pair<int, int> pii;
#define x first
#define y second

int main(){ _
	int a, b;
	while (true){
		cin >> a >> b;
		if (a + b == 0) break;
		pii pa; get(a, pa.x, pa.y);
		pii pb; get(b, pb.x, pb.y);

		int ans = (abs(pa.x-pb.x) + abs(pa.y - pb.y) + abs(pa.x+pa.y-pb.x -pb.y))/2;
		cout << "The distance between cells " << a << " and " << b 
			 << " is " << ans << "." << endl;
	}
	return 0;
}

