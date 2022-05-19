#include <iostream>
#include <vector>
using namespace std;

int num = 0, cnt = 0;
int main() {
	cin >> num;
	vector<int> DP(num+1, -1);
	if (num < 5) DP[3] = 1;
	else {
		DP[3] = 1; DP[5] = 1;
		for (int i = 6; i < num + 1; i++) {
			if (DP[i - 3] == -1 && DP[i - 5] == -1) { continue; }
			if (DP[i - 3] == -1) { DP[i] = DP[i - 5] + 1; continue; }
			if (DP[i - 5] == -1) { DP[i] = DP[i - 3] + 1; continue; }
			DP[i] = min(DP[i - 3] + 1, DP[i - 5] + 1);
		}
	}

	cout << DP[num];
}
