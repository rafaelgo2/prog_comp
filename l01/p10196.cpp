#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

bool valid(int i, int j){
	return 0 <= i && i < 8 && 0 <= j && j < 8;
}

bool oposite(char l, char r){
	if (l > r) swap(l, r);
	return (l < 'a') && (r >= 'a');
}

int main(){ _
	char t[9][9];
	int q = 1;
	while (true){
		bool leave = true;
		for (int i = 0; i < 8; i++){
			for (int j = 0; j < 8; j++){
				cin >> t[i][j];
				leave &= t[i][j] == '.';
			}
		}
		if (leave) break;

		int found = -1;
		for (int i = 0; i < 8; i++){
			for (int j = 0; j < 8; j++){
				int k = t[i][j] >= 'A';
				switch (tolower(t[i][j])){
					case 'p':{
						for (int j_ = -1; j_ <= 1; j_ += 2){
							int i_ = (t[i][j] < 'a') ? -1 : 1;
							if  (valid(i+i_, j+j_) &&
								(tolower(t[i+i_][j+j_]) == 'k') &&
								oposite(t[i+i_][j+j_], t[i][j]))
								found = tolower(t[i+i_][j+j_]) == t[i+i_][j+j_];
						}
					}break;
					case 'n':{
						for (int i_ = -2; i_ <= 2; i_ ++){
							for (int j_ = -2; j_ <= 2; j_ ++){
								if (i_ == 0 || j_ == 0) continue;
								if (abs(i_) + abs(j_) != 3) continue;
								if (!valid(i+i_, j+j_)) continue;
								if  (valid(i+i_, j+j_) &&
									tolower(t[i+i_][j+j_]) == 'k' &&
									oposite(t[i+i_][j+j_], t[i][j]))
									found = tolower(t[i+i_][j+j_]) == t[i+i_][j+j_];
							}
						}
					}break;
					case 'b':{	
						for (int i_ = -1; i_ <= 1; i_ += 2){
							for (int j_ = -1; j_ <= 1; j_ += 2){
								int s = 1;
								while ((valid(i+s*i_, j+s*j_)) && (tolower(t[i+s*i_][j+s*j_]) == '.'))
									s++;
								if  (valid(i+s*i_, j+s*j_) &&
									(tolower(t[i+s*i_][j+s*j_]) == 'k') &&
									oposite(t[i+s*i_][j+s*j_], t[i][j]))
									found = tolower(t[i+s*i_][j+s*j_]) == t[i+s*i_][j+s*j_];
							}
						}
					}break;
					case 'r':{
						for (int i_ = -1; i_ <= 1; i_ += 1){
							for (int j_ = -1; j_ <= 1; j_ += 1){
								if ((abs(i_) != 0 && abs(j_) != 0) || (abs(i_) + abs(j_) == 0) ) continue;
								int s = 1;
								while ((valid(i+s*i_, j+s*j_)) && (tolower(t[i+s*i_][j+s*j_]) == '.'))
									s++;
								if  (valid(i+s*i_, j+s*j_) &&
									(tolower(t[i+s*i_][j+s*j_]) == 'k') &&
									oposite(t[i+s*i_][j+s*j_], t[i][j]))
									found = tolower(t[i+s*i_][j+s*j_]) == t[i+s*i_][j+s*j_];
							}
						}
					}break;
					case 'q':{
						for (int i_ = -1; i_ <= 1; i_ += 1){
							for (int j_ = -1; j_ <= 1; j_ += 1){
								if (i_ == 0 && j_ == 0) continue;
								int s = 1;
								while ((valid(i+s*i_, j+s*j_)) && (tolower(t[i+s*i_][j+s*j_]) == '.'))
									s++;
								if  (valid(i+s*i_, j+s*j_) &&
									(tolower(t[i+s*i_][j+s*j_]) == 'k') &&
									oposite(t[i+s*i_][j+s*j_], t[i][j]))
									found = tolower(t[i+s*i_][j+s*j_]) == t[i+s*i_][j+s*j_];
							}
						}
					}break;
					case 'k':{
						for (int i_ = -1; i_ <= 1; i_ += 1){
							for (int j_ = -1; j_ <= 1; j_ += 1){
								if (i_ == 0 && j_ == 0) continue;
								int s = 1;
								if  (valid(i+s*i_, j+s*j_) &&
									(tolower(t[i+s*i_][j+s*j_]) == 'k') &&
									oposite(t[i+s*i_][j+s*j_], t[i][j]))
									found = tolower(t[i+s*i_][j+s*j_]) == t[i+s*i_][j+s*j_];
							}
						}
					}break;
				}
			}
		}
		cout << "Game #" << q++ << ": ";
		if (found == -1)
			cout << "no king is in check." << endl;
		else{
			if (found == 1)
				cout << "black";
			else
				cout << "white";
			cout << " king is in check." << endl;
		}
	}
	return 0;
}

