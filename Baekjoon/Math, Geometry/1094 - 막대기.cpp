#include <iostream>
using namespace std;

int X, cnt = 0;
string bit;

void get_bit() {
	while (X != 0) {
		bit += (X % 2) + '0';
		X /= 2;
	}
}

void get_count() {
	for (int i = 0; i < bit.size(); i++) if (bit[i] == '1') cnt++;
}

int main(void) {
	cin >> X;

	get_bit();
	get_count();
	
	cout << cnt;
	return 0;
}
