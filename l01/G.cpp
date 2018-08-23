#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

char t[9][9];

typedef pair<int, int> pii;

set<pii> moves_;

bool inside(int x){
	return 1 <= x && x <= 8;
}

void valid_move(int i, int j, char player, set<pii> &valid){
	if (t[i][j] != player) return;
	set<pii> moves;
	for (pii p : moves_){
		if (!inside(i+p.first) || !inside(j+p.second)) continue;
		char cel = t[i + p.first][j + p.second];
		if ((cel != '-') && (cel != player))
			moves.insert(p);
	}
	for (pii p : moves){
		for (int s = 2; s <= 8; s++){
			if (!inside(i + s*p.first) || !inside(j + s*p.second)) break;
			char cel = t[i + s*p.first][j + s*p.second];
			if (cel != player && cel != '-') continue;
			if (cel == '-')
				valid.insert(pii(i+s*p.first, j+s*p.second));
			break;
		}
	}
}

set<pii> all_valid_move(char player){
	set<pii> ans;
	for (int i = 1; i <= 8; i++)
		for (int j = 1; j <= 8; j++)
			valid_move(i, j, player, ans);
	return ans;
}

void get_path(int i, int j, char player, set<pii> &valid){
	set<pii> moves;
	for (pii p : moves_){
		if (!inside(i+p.first) || !inside(j+p.second)) continue;
		char cel = t[i + p.first][j + p.second];
		if ((cel != '-') && (cel != player))
			moves.insert(p);
	}
	for (pii p : moves){
		for (int s = 2; s <= 8; s++){
			if (!inside(i + s*p.first) || !inside(j + s*p.second)) break;
			char cel = t[i + s*p.first][j + s*p.second];
			if (cel != player && cel != '-') continue;
			if (cel == player)
				valid.insert(pii(i+s*p.first, j+s*p.second));
			break;
		}
	}
}

int main(){ _
	for (int i = -1; i <= 1; i ++)
		for (int j = -1; j <= 1; j++)
			moves_.insert(pii(i, j));
	moves_.erase(pii(0, 0));


	int q;
	cin >> q;

	while (q--){
		for (int i = 1; i <= 8; i++)
			for (int j = 1; j <= 8; j++)
				cin >> t[i][j];

		char player;
		cin >> player;
		char c;
		while (true){
			cin >> c;

			set<pii> moves = all_valid_move(player);
			switch (c){
				case 'L':{
					if (moves.empty()){
						cout << "No legal move." << endl;
						continue;
					}
					pii p = *moves.begin();
					cout << "(" << p.first << "," << p.second << ")";
					for (set<pii>::iterator it = ++moves.begin(); it != moves.end(); it++){
						p = *it;
						cout << " (" << p.first << "," << p.second << ")";
					}
					cout << endl;
				} break;
				case 'M':{
					char y, x;
					cin >> y >> x;
					pii aux(y-'0', x-'0');
					if (!moves.count(aux))
						player = (player == 'W') ? 'B' : 'W';
					set<pii> dest;
					get_path(aux.first, aux.second, player, dest);
					for (pii p : dest){
						int i = aux.first, j = aux.second;
						while (i != p.first || j != p.second){
						 t[i][j] = player;
						 if (p.first != i)
							 i += (p.first-i)/abs(p.first-i);
						 if (p.second != j)
							 j += (p.second-j)/abs(p.second-j);
						}
						t[p.first][p.second] = player;
					}
					int c[3] = {0, 0, 0};
					for (int i = 1; i <= 8; i++)
						for (int j = 1; j <= 8; j++)
						 c[t[i][j] == 'W' ? 2 : t[i][j] == 'B']++;
					cout << "Black - " << setw(2) << c[1] << " "
						 << "White - " << setw(2) << c[2] << endl;
					player = (player == 'W') ? 'B' : 'W';
				} break;
				case 'Q':{
					for (int i = 1; i <= 8; i++){
						for (int j = 1; j <= 8; j++)
							cout << t[i][j];
						cout << endl;
					}
				} break;
			}
			if (c == 'Q') break;
		}
		if (q != 0) cout << endl;
	}	
	return 0;
}

