#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int col = 0, row = 0, temp = 0, max_v = 0;
bool is_rot = false;
vector<vector<int>> toma;
queue<pair<int, int>> q;
vector<pair<int, int>> coord;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void bfs(vector<vector<bool>>& visit) {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second; q.pop();
		max_v = toma[x][y];

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if ((nx >= 0 && nx < row) && (ny >= 0 && ny < col)) {
				if (!visit[nx][ny] && !toma[nx][ny]) {
					visit[nx][ny] = true;
					q.push(make_pair(nx, ny));
					toma[nx][ny] = toma[x][y] + 1;
				}
			}
		}
	}
}

void init_queue(vector<vector<bool>>& visit) {
	for (int i = 0; i < coord.size(); i++) {
		visit[coord[i].first][coord[i].second] = true;
		q.push(coord[i]);
	}
}

void check_rot() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			if (toma[i][j] == 0) { is_rot = true; break; }
	}
}

int main(void) {
	cin >> col >> row;
	vector<vector<bool>> visit(row, vector<bool>(col, 0));

	for (int i = 0; i < row; i++) {
		vector<int> temp_v;
		for (int j = 0; j < col; j++) {
			cin >> temp;
			if (temp == 1) coord.push_back(make_pair(i, j));
			temp_v.push_back(temp);
		}
		toma.push_back(temp_v);
	}

	init_queue(visit);
	bfs(visit);
	check_rot();

	if (is_rot) cout << -1;
	else cout << max_v - 1;
}
