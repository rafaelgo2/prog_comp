#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

//find_by_order() returns an iterator to the k-th largest element (counting from zero

// order_of_key() returns the number of items in a set that are strictly smaller than our item

int main(){ _
	int n;
	cin >> n;
	int v;
	ordered_set s;
	for (int i = 0; i < n; i++){
		cin >> v;
		if (i != 0) cout << " ";
		cout << v - s.order_of_key(v);
		s.insert(v);
	}
	cout << endl;
	return 0;
}
