#include <iostream>
using namespace std;

int n = 0, sum = 0;
string res;

void make_input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		char temp = '0';
		cin >> temp;
		res += temp;
	}
}

void calc_sum() {
	for (int i = 0; i < n; i++) sum += (res[i] - '0');
	cout << sum;
}

int main(void) {

	make_input();
	calc_sum();

	return 0;
}
