#include <iostream>
#include <vector>
using namespace std;

int n = 0, m = 0, temp = 0, qa = 0, qb = 0;
int main() {
	cin >> n >> m;
	vector<int> DP(n + 1, 0);
	for (int i = 1; i < n+1; i++) {
		cin >> temp;
		DP[i] = DP[i - 1] + temp;
	}

	DP[0] = 0;

	for (int i = 0; i < m; i++) {
		cin >> qa >> qb;
		cout << DP[qb] - DP[qa-1] << '\n';
	}
	return 0;
}
