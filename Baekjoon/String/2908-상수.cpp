#include <iostream>
#include <string>
using namespace std;

int a, b;

int num_flip(int a, int b) {
	int new_a, new_b;
	new_a = (a % 10) * 100 + ((a % 100) / 10) * 10 + a/100;
	new_b = (b % 10) * 100 + ((b % 100) / 10) * 10 + b / 100;
	
	return new_a > new_b ? new_a : new_b;
}

int main() {
	cin >> a >> b;
	cout << num_flip(a, b);
	return 0;
}
