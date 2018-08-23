#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const double pi = acos(-1);

int main(){ _
	cout << fixed << setprecision(3);
	double n, d;
	cin >> n >> d;
	if (d <= n/2){
		cout << pi*d*d << endl;
		return 0;
	}
	else if (d*d >= (n*n)/2){
		cout << n*n << endl;
		return 0;
	}
	double theta = acos(n/(2*d));
	double phi = (pi/2) - 2*theta;
	double arc = phi*d*d/2;
	double tri = (sin(theta)*d)*(cos(theta)*d)/2;
	cout << 4*arc + 8*tri << endl;
	return 0;
}
