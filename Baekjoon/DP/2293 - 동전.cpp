#include <iostream>
#include <vector>
using namespace std;

vector<int> money;

int main() {
	int n = 0, k = 0, money_temp = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> money_temp;
		money.push_back(money_temp);
	}

	vector<int> DP(k+1, 0);
	DP[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = money[i]; j <= k; j++) {
			DP[j] += DP[j - money[i]];
		}
	}

	cout << DP[k];
	return 0;
}
