#include <iostream>
#include <vector>
using namespace std;

int n = 0, cnt = 0;
bool check(int depth, vector<int>& visit) { // 놓을 수 있는 위치인지 검사한다.
	for (int i = 0; i < depth; i++)
		if (visit[i] == visit[depth] || abs(visit[depth] - visit[i]) == depth - i) // 먼저 같은 선상에 있는지 앞에서 검사하고
			return false;                          // x값의 차이와 y값이 차이가 같으면 대각선에 위치해있다는 말!
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
