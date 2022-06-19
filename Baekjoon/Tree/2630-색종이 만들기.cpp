#include <iostream>
#include <vector>
using namespace std;

int n = 0, blue = 0, white = 0;
vector<vector<int>> maps(129, (vector<int>(129, 0)));

void quadtree(int x, int y, int limit) {
	int temp = 0;
	for (int i = x; i < x + limit; i++) {
		for (int j = y; j < y + limit; j++) {
			if (maps[i][j] == 1) temp++; // 내가 설정해놓은 Limit만큼만 돌면서 1의 갯수를 확인한다.
		}
	}

	if (temp == 0) white++; // 1이 1개도 없는 0으로만 이루어진 사각형이라면 WHITE
	else if (temp == limit * limit) blue++; // 1만 존재하는 사각형이라면 BLUE
	else {
		quadtree(x, y, limit/2); // 1사분면 탐색
		quadtree(x, y + limit/2, limit/2); // 3사분면 탐색
		quadtree(x + limit/2, y, limit/2); // 2사분면 탐색
		quadtree(x + limit/2, y + limit/2, limit/2); // 4사분면 탐색
	}
	return;
}

int main(void) {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> maps[i][j];
		}
	}

	quadtree(0, 0, n);
	cout << white << "\n";
	cout << blue;
	return 0;
}
