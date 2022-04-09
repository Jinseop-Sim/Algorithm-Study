#include <iostream>
#include <vector>
using namespace std;

vector<int> DP(11, 0);
void make_dp() {
	DP[0] = 1; DP[1] = 2; DP[2] = 4; // Base Condition
	for (int i = 3; i < 10; i++) DP[i] = DP[i - 1] + DP[i - 2] + DP[i - 3];
}
int main() {
	int t = 0, n = 0;
	cin >> t;
	make_dp();
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << DP[n-1] << endl;
	}
	return 0;
}
