#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>

using namespace __gnu_pbds;

typedef trie<string,
null_type,
trie_string_access_traits<>,
pat_trie_tag,
trie_prefix_search_node_update>
prefix_trie;


//it sao as strings que tem s como prefixo
int main(){ _
	int n;
	cin >> n;
	prefix_trie p;
	string s;
	for (int i = 0; i < n; i++){
		cin >> s;
		p.insert(s);
	}
	cin >> s;
	auto range = p.prefix_range(s);
	for (auto it = range.first; it != range.second;it++){
		cout << *it << endl;
	}
	return 0;
}
