#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n = 0, m = 0, temp = 0;
int main() {
	cin >> n >> m;
	vector<int> DP(n + 1, 0);
	vector<int> DP_2(n - m + 1, 0);
	for (int i = 1; i < n+1; i++) {
		cin >> temp;
		DP[i] = DP[i - 1] + temp;
	}

	for (int i = m; i < n+1; i++) {
		DP_2[i-m] = DP[i] - DP[i - m];
	}
	
	cout << *max_element(DP_2.begin(), DP_2.end());
	return 0;
}
