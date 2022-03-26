#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<vector<int>> chessboard(8, vector<int>(8));
map<char, int> coord;
string king, stone;
void coord_token() {
	coord['A'] = 0; coord['B'] = 1; coord['C'] = 2; coord['D'] = 3; coord['E'] = 4;
	coord['F'] = 5; coord['G'] = 6; coord['H'] = 7;
}

int switch_token(string command) {
	int token = 0;
	vector<string> commands = { "R", "L", "B", "T", "RT", "LT", "RB", "LB" };
	for (int i = 0; i < commands.size(); i++) if (commands[i] == command) token = i+1;
	return token;
}

void mv_right() {
	string temp1, temp2;
	if (chessboard[8 - (king[1] - '0')][coord[king[0]] + 1] == 2) {
		if (coord[stone[0]] + 1 > 7) return;
		swap(chessboard[8 - (stone[1] - '0')][coord[stone[0]]], chessboard[8 - (stone[1] - '0')][coord[stone[0]] + 1]);
		temp1 = stone[0] + 1; temp2 = stone[1];
		stone = temp1 + temp2;
	}
	swap(chessboard[8 - (king[1] - '0')][coord[king[0]]], chessboard[8 - (king[1] - '0')][coord[king[0]] + 1]);
	temp1 = king[0] + 1; temp2 = king[1];
	king = temp1 + temp2;
}
void mv_left() { 
	string temp1, temp2;
	if (chessboard[(8 - (king[1] - '0'))][coord[king[0]] - 1] == 2) {
		if (coord[stone[0]] - 1 < 0) return;
		swap(chessboard[8 - (stone[1] - '0')][coord[stone[0]]], chessboard[(8 - (stone[1] - '0'))][coord[stone[0]] - 1]);
		temp1 = stone[0] - 1; temp2 = stone[1];
		stone = temp1 + temp2;
	}
	swap(chessboard[8 - (king[1] - '0')][coord[king[0]]], chessboard[8 - (king[1] - '0')][coord[king[0]] - 1]);
	temp1 = king[0] - 1; temp2 = king[1];
	king = temp1 + temp2;
}
void mv_down() { 
	string temp1, temp2;
	if (chessboard[(8 - (king[1] - '0')) + 1][coord[king[0]]] == 2) {
		if ((8 - (stone[1] - '0')) + 1 > 7) return;
		swap(chessboard[8 - (stone[1] - '0')][coord[stone[0]]], chessboard[(8 - (stone[1] - '0')) + 1][coord[stone[0]]]);
		temp1 = stone[0]; temp2 = stone[1] - 1;
		stone = temp1 + temp2;
	}
	swap(chessboard[8 - (king[1] - '0')][coord[king[0]]], chessboard[(8 - (king[1] - '0')) + 1][coord[king[0]]]);
	temp1 = king[0]; temp2 = king[1] - 1;
	king = temp1 + temp2;
}
void mv_up() { 
	string temp1, temp2;
	if (chessboard[(8 - (king[1] - '0')) - 1][coord[king[0]]] == 2) {
		if ((8 - (stone[1] - '0')) - 1 < 0) return;
		swap(chessboard[8 - (stone[1] - '0')][coord[stone[0]]], chessboard[(8 - (stone[1] - '0')) - 1][coord[stone[0]]]);
		temp1 = stone[0]; temp2 = stone[1] + 1;
		stone = temp1 + temp2;
	}
	swap(chessboard[8 - (king[1] - '0')][coord[king[0]]], chessboard[(8 - (king[1] - '0')) - 1][coord[king[0]]]);
	temp1 = king[0]; temp2 = king[1] + 1;
	king = temp1 + temp2;
}
void mv_up_right() {
	string temp1, temp2;
	if (chessboard[(8 - (king[1] - '0')) - 1][coord[king[0]] + 1] == 2) {
		if ((8 - (stone[1] - '0')) - 1 < 0) return;
		swap(chessboard[8 - (stone[1] - '0')][coord[stone[0]]], chessboard[(8 - (stone[1] - '0')) - 1][coord[stone[0]] + 1]);
		temp1 = stone[0] + 1; temp2 = stone[1] + 1;
		stone = temp1 + temp2;
	}
	swap(chessboard[8 - (king[1] - '0')][coord[king[0]]], chessboard[(8 - (king[1] - '0')) - 1][coord[king[0]] + 1]);
	temp1 = king[0] + 1; temp2 = king[1] + 1;
	king = temp1 + temp2;
}
void mv_up_left() {
	string temp1, temp2;
	if (chessboard[(8 - (king[1] - '0')) - 1][coord[king[0]] - 1] == 2) {
		if ((8 - (stone[1] - '0')) - 1 < 0) return;
		swap(chessboard[8 - (stone[1] - '0')][coord[stone[0]]], chessboard[(8 - (stone[1] - '0')) - 1][coord[stone[0]] - 1]);
		temp1 = stone[0] - 1; temp2 = stone[1] + 1;
		stone = temp1 + temp2;
	}
	swap(chessboard[8 - (king[1] - '0')][coord[king[0]]], chessboard[(8 - (king[1] - '0')) - 1][coord[king[0]] - 1]);
	temp1 = king[0] - 1; temp2 = king[1] + 1;
	king = temp1 + temp2;
}
void mv_down_right(){
	string temp1, temp2;
	if (chessboard[(8 - (king[1] - '0')) + 1][coord[king[0]] + 1] == 2) {
		if ((8 - (stone[1] - '0')) + 1 > 7) return;
		swap(chessboard[8 - (stone[1] - '0')][coord[stone[0]]], chessboard[(8 - (stone[1] - '0')) + 1][coord[stone[0]] + 1]);
		temp1 = stone[0] + 1; temp2 = stone[1] - 1;
		stone = temp1 + temp2;
	}
	swap(chessboard[8 - (king[1] - '0')][coord[king[0]]], chessboard[(8 - (king[1] - '0')) + 1][coord[king[0]] + 1]);
	temp1 = king[0] + 1; temp2 = king[1] - 1;
	king = temp1 + temp2;
}
void mv_down_left() {
	string temp1, temp2;
	if (chessboard[(8 - (king[1] - '0')) + 1][coord[king[0]] - 1] == 2) {
		if ((8 - (stone[1] - '0')) + 1 > 7) return;
		swap(chessboard[8 - (stone[1] - '0')][coord[stone[0]]], chessboard[(8 - (stone[1] - '0')) + 1][coord[stone[0]] - 1]);
		temp1 = stone[0] - 1; temp2 = stone[1] - 1;
		stone = temp1 + temp2;
	}
	swap(chessboard[8 - (king[1] - '0')][coord[king[0]]], chessboard[(8 - (king[1] - '0')) + 1][coord[king[0]] - 1]);
	temp1 = king[0] - 1; temp2 = king[1] - 1;
	king = temp1 + temp2;
}

int main() {
	coord_token();
	string command;
	int n = 0;
	cin >> king >> stone >> n;
	chessboard[8-(king[1]-'0')][coord[king[0]]] = 1;
	chessboard[8-(stone[1]-'0')][coord[stone[0]]] = 2;

	for (int i = 0; i < n; i++) {
		cin >> command;
		switch(switch_token(command)) {
		case 1:
			if (coord[king[0]] + 1 < 8) { mv_right(); break; }
			else break;
		case 2:
			if (coord[king[0]] - 1 > 0) { mv_left(); break; }
			else break;
		case 3:
			if ((8 - (king[1] - '0')) + 1 < 8) { mv_down(); break; }
			else break;
		case 4:
			if ((8 - (king[1] - '0')) - 1 > 0) { mv_up(); break; }
			else break;
		case 5:
			if ((8 - (king[1] - '0')) - 1 > 0 && coord[king[0]] + 1 < 8) { mv_up_right(); break; }
			else break;
		case 6:
			if ((8 - (king[1] - '0')) - 1 > 0 && coord[king[0]] - 1 > 0) { mv_up_left(); break; }
			else break;
		case 7:
			if ((8 - (king[1] - '0')) + 1 < 8 && coord[king[0]] + 1 < 8) { mv_down_right(); break; }
			else break;
		case 8:
			if ((8 - (king[1] - '0')) + 1 < 8 && coord[king[0]] - 1 > 0) { mv_down_left(); break; }
			else break;
		}
	}

	cout << king << endl;
	cout << stone;

	return 0;
}
