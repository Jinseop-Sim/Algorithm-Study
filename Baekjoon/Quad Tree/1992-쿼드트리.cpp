#include <iostream>
#include <vector>
using namespace std;

int n = 0;
void quadtree(int x, int y, int limit, vector<vector<int>> &maps) {
	if (limit == 1) {
		cout << maps[y][x];
		return;
	}

	bool zero_only = true, one_only = true;
	for (int i = x; i < x + limit; i++) {
		for (int j = y; j < y + limit; j++) {
			if (maps[j][i]) zero_only = false;
			else one_only = false;
		}
	}

	if (zero_only) cout << 0;
	else if (one_only) cout << 1;
	else {
		cout << "(";
		quadtree(x, y, limit / 2, maps);
		quadtree(x + limit / 2, y, limit / 2, maps);
		quadtree(x, y + limit / 2, limit / 2, maps);
		quadtree(x + limit / 2, y + limit / 2, limit / 2, maps);
		cout << ")";
	}
	return;
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
