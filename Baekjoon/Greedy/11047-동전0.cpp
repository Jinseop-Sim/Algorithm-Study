#include <iostream>
#include <vector>
using namespace std;

vector<int> money;

void put_money(int n) {
	for (int i = 0; i < n; i++) {
		int temp = 0;
		cin >> temp; money.push_back(temp);
	}
}

int calc(int iter, int k) {
	int cnt = 0;
	while (k != 0) {
		if (k - money[iter] < 0) iter--;
		else { k = k - money[iter]; cnt++; }
	}

	return cnt;
}

int main() {
	int n = 0, k = 0, cnt = 0;
	cin >> n >> k;
	int iter = n-1;
	
	put_money(n);
	cout << calc(iter, k);
	return 0;
}
