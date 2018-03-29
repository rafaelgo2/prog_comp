#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

bool is_vowel(char c){
	c = tolower(c);
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; 
}

bool is_alpha(char c){
	c = tolower(c);
	return 'a'<= c && c <= 'z';
}

int main(){ _
	string s, w;
	while (getline(cin, s)){
		int i = 0;
		while (i < s.size()){
			while (i < s.size() && !is_alpha(s[i]))
				cout << s[i++];
			w = "";
			while (i < s.size() && is_alpha(s[i]))
				w += s[i++];
			if (i == s.size()) break;
			if (is_vowel(w.front())){
				cout << w;
			}
			else{
				cout << string(w.begin() + 1, w.end());
				cout << w.front();
			}
			cout << "ay";
		}
		cout << endl;
	}
	return 0;
}
