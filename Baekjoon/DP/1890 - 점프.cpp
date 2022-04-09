#include <iostream>
#include <vector>
using namespace std;

void make_dp(vector<vector<long>>& DP, vector<vector<int>> maps, int wall) {
	bool is_first = true;
	for (int i = 0; i < wall; i++) {
		for (int j = 0; j < wall; j++) {
			int factor = maps[i][j];
			if (i == wall - 1 && j == wall - 1) break;
			if (is_first) { DP[i + factor][j] = 1; DP[i][j + factor] = 1; is_first = false; continue; }
			else {
				if (DP[i][j] == 0) continue;
				if (i + factor >= wall && j + factor >= wall) continue;
				if (i + factor >= wall) { DP[i][j + factor] += DP[i][j]; continue; }
				if (j + factor >= wall) { DP[i + factor][j] += DP[i][j]; continue; }
				DP[i + factor][j] += DP[i][j];
				DP[i][j + factor] += DP[i][j];
			}
		}
	}
}

int main() {
	int n = 0;
	cin >> n;
	vector<vector<int>> maps(n, vector<int>(n));
	vector<vector<long>> DP(n, vector<long>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> maps[i][j];
		}
	}

	make_dp(DP, maps, n);
	cout << DP[n - 1][n - 1];

	return 0;
}

// 경로의 총 개수가 2^63 - 1개 보다 작거나 같다고 했다.
// 이는 Int의 최대 값인 2^31 -1 보다 큰 값이므로, DP 배열을 int로 선언해서는 안된다.
// 따라서 더 큰 자료형인 Long으로 선언을 한다.
