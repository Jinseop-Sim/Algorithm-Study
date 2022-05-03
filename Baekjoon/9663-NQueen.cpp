#include <iostream>
#include <vector>
using namespace std;

int n = 0, cnt = 0;
bool check(int depth, vector<int>& visit) {
	for (int i = 0; i < depth; i++)
		if (visit[i] == visit[depth] || abs(visit[depth] - visit[i]) == depth - i)
			return false;
	return true;
}

void backtrack(int depth, vector<int>& visit) {
	if (depth == n) {
		cnt++;
		return;
	}

	for (int i = 0; i < n; i++) {
		visit[depth] = i;
		if (check(depth, visit)) backtrack(depth + 1, visit);
	}
}

int main(void) {
	cin >> n;
	vector<int> visit(n, 0);
	backtrack(0, visit);
	
	cout << cnt;
}
