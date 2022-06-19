#include <iostream>
#include <vector>
using namespace std;

int n = 0;
void quadtree(int x, int y, int limit, vector<vector<int>> &maps) {
	if (limit == 1) {           // 마지막까지 깊게 들어가서 길이가 1인 사각형이 되면, 출력한다.
		cout << maps[y][x];
		return;
	}

	bool zero_only = true, one_only = true;
	for (int i = x; i < x + limit; i++) {
		for (int j = y; j < y + limit; j++) {
			if (maps[j][i]) zero_only = false; // 해당 사분면을 모두 탐색해서 전부 1이면 one_only가 true로 남고
			else one_only = false; // 전부 0이면 zero_only가 true로 남는다.
		}
	}

	if (zero_only) cout << 0; // 전부 0인 경우에, 괄호 없이 0 출력
	else if (one_only) cout << 1; // 전부 1인 경우에, 괄호 없이 0 출력
	else {
		cout << "(";  // 사분면을 탐색할 때, 각 사분면은 괄호로 구분하도록 되어있다.
		quadtree(x, y, limit / 2, maps); // 2사분면
		quadtree(x + limit / 2, y, limit / 2, maps); // 1사분면
		quadtree(x, y + limit / 2, limit / 2, maps); // 3사분면
		quadtree(x + limit / 2, y + limit / 2, limit / 2, maps); // 4사분면
		cout << ")";
	}
	return; // 탐색이 끝나면 종료한다.
}

int main(void) {
	cin >> n;
	vector<vector<int>> maps(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < n; j++) {
			maps[i][j] = temp[j] - '0';
		}
	}

	quadtree(0, 0, n, maps);
	return 0;
}
