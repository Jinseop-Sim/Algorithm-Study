#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> paper(100, vector<int>(100));

int make_map() {
	int n = 0, x = 0, y = 0;
	int area = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		for (int row = x; row < x + 10; row++) {
			for (int col = y; col < y + 10; col++) {
				if (paper[row][col] == 1) continue;
				paper[row][col] = 1; area += 1;
			}
		}
	}

	return area;
}

int main() {
	cout << make_map();
	return 0;
}
