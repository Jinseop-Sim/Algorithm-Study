#include <iostream>
#include <vector>
using namespace std;

void make_map(vector<vector<int>>& maps, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> maps[i][j];
		}
	}
}

int row_search(vector<vector<int>> maps, int len, int row) {
	int cnt = 0;
	for (int i = 0; i < row; i++) {
		bool is_road = true;
		vector<bool> check(row, 0);
		for (int j = 1; j < row; j++) {
			if (abs(maps[i][j] - maps[i][j - 1]) >= 2) { is_road = false;  break; } // 차이가 2이상이면 경사로X
			if (maps[i][j] > maps[i][j - 1]) {
				if (j - len < 0) { is_road = false; break; } // 경사로가 벗어날 때
				
				int flat = maps[i][j - 1];
				for (int k = j - 1; k >= (j - len); k--) {
					if (maps[i][k] != flat || check[k]) { is_road = false; break; }
				} 
				if (!is_road) break;
				else for (int k = j - 1; k >= j - len; k--) check[k] = true;
			} // 뒤가 현재보다 1 낮을 때

			if (maps[i][j] < maps[i][j - 1]) {
				if (j + len - 1 >= row) { is_road = false; break; } // 경사로가 벗어날 때
				int flat = maps[i][j];
				for (int k = j; k < j + len; k++) {
					if (maps[i][k] != flat || check[k]) { is_road = false; break; }
				}
				if (!is_road) break;
				else {
					for (int k = j; k < j + len; k++) check[k] = true;
					j += (len - 1); // 경사로를 깔았으니, j를 그만큼 Jump시킨다.
				}
			} // 뒤가 현재보다 1 높을 때
		}
		if (is_road) cnt++;
	}
	
	return cnt;
}

int col_search(vector<vector<int>> maps, int len, int col) {
	int cnt = 0;
	for (int i = 0; i < col; i++) {
		bool is_road = true;
		vector<bool> check(col, 0);
		for (int j = 1; j < col; j++) {
			if (abs(maps[j][i] - maps[j-1][i]) >= 2) { is_road = false;  break; } // 차이가 2이상이면 경사로X
			if (maps[j][i] > maps[j-1][i]) {
				if (j - len < 0) { is_road = false; break; } // 경사로가 벗어날 때

				int flat = maps[j-1][i];
				for (int k = j - 1; k >= (j - len); k--) {
					if (maps[k][i] != flat || check[k]) { is_road = false; break; }
				}
				if (!is_road) break;
				else for (int k = j - 1; k >= j - len; k--) check[k] = true;
			} // 뒤가 현재보다 1 낮을 때

			if (maps[j][i] < maps[j-1][i]) {
				if (j + len - 1 >= col) { is_road = false; break; } // 경사로가 벗어날 때

				int flat = maps[j][i];
				for (int k = j; k < j + len; k++) {
					if (maps[k][i] != flat || check[k]) { is_road = false; break; }
				}
				if (!is_road) break;
				else {
					for (int k = j; k < j + len; k++) check[k] = true;
					j += (len - 1); // 경사로를 깔았으니, j를 그만큼 Jump시킨다.
				}
			} // 뒤가 현재보다 1 높을 때
		}
		if (is_road) cnt++;
	}
	return cnt;
}

int main() {
	int n = 0, l = 0, res = 0;
	cin >> n >> l;
	vector<vector<int>> maps(n, vector<int>(n));
	make_map(maps, n);
	res = row_search(maps, l, n) + col_search(maps, l, n);
	cout << res;
	return 0;
}
