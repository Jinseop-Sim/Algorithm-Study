#include <iostream>
#include <map>
using namespace std;

map<char, int> alpha_list;
string dial;
int sum;
void make_map() {
	alpha_list['A'] = 3; alpha_list['B'] = 3; alpha_list['C'] = 3;
	alpha_list['D'] = 4; alpha_list['E'] = 4; alpha_list['F'] = 4;
	alpha_list['G'] = 5; alpha_list['H'] = 5; alpha_list['I'] = 5;
	alpha_list['J'] = 6; alpha_list['K'] = 6; alpha_list['L'] = 6;
	alpha_list['M'] = 7; alpha_list['N'] = 7; alpha_list['O'] = 7;
	alpha_list['P'] = 8; alpha_list['Q'] = 8; alpha_list['R'] = 8; alpha_list['S'] = 8;
	alpha_list['T'] = 9; alpha_list['U'] = 9; alpha_list['V'] = 9;
	alpha_list['W'] = 10; alpha_list['X'] = 10; alpha_list['Y'] = 10; alpha_list['Z'] = 10;
}

int main() {
	make_map();

	cin >> dial;
	for (int i = 0; i < dial.length(); i++) sum += alpha_list[dial[i]];
	cout << sum;

	return 0;
}
