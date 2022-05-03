#include <iostream>
#include <vector>
using namespace std;

int n = 0, m = 0;
void backtrack(int num, int depth, vector<bool>& visit, vector<int>& seq) {
	if (depth == m) {
		for (auto i : seq) cout << i << " ";
		cout << "\n";
		return;
	}
	
	for (int i = num; i <= n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			seq[depth] = i;
			backtrack(i + 1, depth + 1, visit, seq);
			visit[i] = false;
		}
	}
}

int main(void) {
	cin >> n >> m;
	vector<int> seq(m, 0);
	vector<bool> visit(n+1, 0);
	backtrack(1, 0, visit, seq);
	return 0;
}
