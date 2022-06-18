#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n = 0, cnt = 0, cnt_weak = 0;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
queue<pair<int, int>> q;

void clear_visit(vector<vector<bool>>& visit) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visit[i][j] = false;
		}
	}
}

void bfs(int st_x, int st_y, vector<vector<char>>& RGB, vector<vector<bool>>& visit) {
	visit[st_x][st_y] = true;
	q.push(make_pair(st_x, st_y));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second; q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if ((nx >= 0 && nx < n) && (ny >= 0 && ny < n)) {
				if (!visit[nx][ny] && (RGB[x][y] == RGB[nx][ny])) {
					visit[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int main(void) {
	cin >> n;

	vector<vector<char>> RGB(n, vector<char>(n, '0'));
	vector<vector<char>> RGB_weak(n, vector<char>(n, '0'));
	vector<vector<bool>> visit(n, vector<bool>(n, false));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> RGB[i][j];
			if (RGB[i][j] == 'R' || RGB[i][j] == 'G')  RGB_weak[i][j] = '#';
			else RGB_weak[i][j] = RGB[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visit[i][j]) {
				bfs(i, j, RGB, visit);
				cnt++;
			}
		}
	}

	clear_visit(visit);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visit[i][j]) {
				bfs(i, j, RGB_weak, visit);
				cnt_weak++;
			}
		}
	}

	cout << cnt << " " << cnt_weak;
	return 0;
}
