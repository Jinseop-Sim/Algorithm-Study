#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n = 0, limit = 0, max_h = 0, max_v = 0, safe_zone = 0;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
queue<pair<int, int>> q;

void bfs(int st_x, int st_y, int limit, vector<vector<int>>& maps, vector<vector<bool>>& visit) {
	q.push(make_pair(st_x, st_y));
	visit[st_x][st_y] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if ((nx >= 0 && nx < n) && (ny >= 0 && ny < n)) {
				if (!visit[nx][ny] && maps[nx][ny] > limit) {
					visit[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}
void make_map(vector<vector<int>>& maps) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> maps[i][j];
			if (maps[i][j] > max_h) max_h = maps[i][j];
		}
	}
}

void clean_visit(vector<vector<bool>>& visit) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visit[i][j] = false;
		}
	}
}

void calc_safe(vector<vector<int>>& maps, vector<vector<bool>>& visit) {
	while (limit <= max_h) {
		clean_visit(visit); safe_zone = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visit[i][j] && maps[i][j] > limit) {
					bfs(i, j, limit, maps, visit);
					safe_zone++;
				}
			}
		}

		if (safe_zone > max_v) max_v = safe_zone;
		limit++;
	}
}

int main(void) {
	cin >> n;
	vector<vector<int>> maps(n, vector<int>(n, 0));
	vector<vector<bool>> visit(n, vector<bool>(n, false));

	make_map(maps);
	calc_safe(maps, visit);

	cout << max_v;
	return 0;
}
