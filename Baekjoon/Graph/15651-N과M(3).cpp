#include <iostream>
#include <vector>
using namespace std;

int n = 0, m = 0;
void backtrack(int depth, vector<bool>& visit, vector<int>& seq) {
	if (depth == m) {
		for (auto i : seq) cout << i << " ";
		cout << "\n";
		return;
	}
	
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			seq[depth] = i;
			backtrack(depth + 1, visit, seq);
		}
	}
}

int main(void) {
	cin >> n >> m;
	vector<int> seq(m, 0);
	vector<bool> visit(n+1, 0);
	backtrack(0, visit, seq);
	return 0;
}
