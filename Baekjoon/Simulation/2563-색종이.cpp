#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> paper(100, vector<int>(100));

void make_map() {
	int n = 0, x = 0, y = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		for (int row = x; row < x + 10; row++) {
			for (int col = y; col < y + 10; col++) {
				if (paper[row][col] == 1) continue;
				paper[row][col] = 1;
			}
		}
	}
}

int count_area() {
	int area = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (paper[i][j] == 1) area += 1;
		}
	}

	return area;
}
int main() {
	make_map();

	cout << count_area();

	return 0;
}
