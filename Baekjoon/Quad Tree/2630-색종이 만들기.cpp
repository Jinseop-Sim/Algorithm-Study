#include <iostream>
#include <vector>
using namespace std;

int n = 0, blue = 0, white = 0;
vector<vector<int>> maps(129, (vector<int>(129, 0)));

void quadtree(int x, int y, int limit) {
	int temp = 0;
	for (int i = x; i < x + limit; i++) {
		for (int j = y; j < y + limit; j++) {
			if (maps[i][j] == 1) temp++;
		}
	}

	if (temp == 0) white++;
	else if (temp == limit * limit) blue++;
	else {
		quadtree(x, y, limit/2);
		quadtree(x, y + limit/2, limit/2);
		quadtree(x + limit/2, y, limit/2);
		quadtree(x + limit/2, y + limit/2, limit/2);
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
