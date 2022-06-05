#include <iostream>
#include <vector>
using namespace std;
#define endl "\n"

int ti;
int button[3] = {300, 60, 10};
int ans[3] = { 0, };

void calc(int ti) {
	if (ti >= 300) {
		ans[0] = ti / 300;
		ti = ti - (300 * (ti / 300));
	}
	if (ti >= 60) {
		ans[1] = ti / 60;
		ti = ti - (60 * (ti / 60));
	}
	if (ti >= 10) {
		ans[2] = ti / 10;
		ti = ti - (10 * (ti / 10));
	}
}

int main(void) {
	cin >> ti;

	calc(ti);

	if (ti != 0) cout << -1;
	else for (auto i : ans) cout << i << " ";

	return 0;
}

// 간단한 Greedy 문제였다.
