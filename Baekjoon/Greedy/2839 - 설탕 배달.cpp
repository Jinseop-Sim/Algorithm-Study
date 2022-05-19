#include <iostream>
using namespace std;

int num = 0, cnt = 0;
int main() {
	cin >> num;

	while (num >= 0) {
		if (num % 5 == 0) {
			cnt += num / 5;
			cout << cnt;
			return 0;
		}
		num -= 3; cnt++;
	}

	cout << -1;
}
