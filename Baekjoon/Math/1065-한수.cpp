#include <iostream>
using namespace std;

int num = 0, cnt = 99;
void hansoo() {
	for (int i = 111; i < num + 1; i++) {
		if ((i / 100 - (i / 10) % 10) == ((i / 10) % 10) - i % 10) cnt += 1;
	}
}

int main() {
	cin >> num;
	if (num <= 99) cout << num;
	else {
		hansoo();
		cout << cnt;
	}
	return 0;
}
