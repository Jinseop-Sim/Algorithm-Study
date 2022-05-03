#include <iostream>
#include <vector>
using namespace std;

int n = 0, m = 0;
void backtrack(int depth, vector<bool>& visit, vector<int>& seq) {
	if (depth == m) {
		for (auto i : seq) cout << i << " ";
		cout << "\n"; // cout << endl을 쓰는 경우엔 시간 초과가 발생했다. 왜?
		return;
	}
	
	for (int i = 1; i < n+1; i++) {
		if (!visit[i]) {
			visit[i] = true;
			seq[depth] = i;
			backtrack(depth + 1, visit, seq);
			visit[i] = false;
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
