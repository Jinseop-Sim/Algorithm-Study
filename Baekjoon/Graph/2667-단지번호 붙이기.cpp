#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int row = 0, cnt = 0;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
priority_queue<int, vector<int>, greater<int>> answer;
vector<vector<int>> apt_map;
queue<pair<int, int>> q;

void bfs(int f_x, int f_y, vector<vector<bool>>& visit) {
	q.push(make_pair(f_x, f_y));

	visit[f_x][f_y] = true;
	cnt++;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if ((nx >= 0 && nx < row) && (ny >= 0 && ny < row)) {
				if (!visit[nx][ny] && apt_map[nx][ny]) {
					q.push(make_pair(nx, ny));
					visit[nx][ny] = true;
					cnt++;
				}
			}
		}
	}
}

int main() {
	cin >> row;
	vector<vector<bool>> visit(row, vector<bool>(row, false));

	for (int i = 0; i < row; i++) {
		vector<int> temp_v;
		string temp; cin >> temp;
		for (int j = 0; j < row; j++) temp_v.push_back(temp[j] - '0');
		apt_map.push_back(temp_v);
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < row; j++) {
			if (!visit[i][j] && apt_map[i][j]) { 
				cnt = 0;
				bfs(i, j, visit); 
				answer.push(cnt);
			}
		}
	}

	cout << answer.size() << '\n';
	while (!answer.empty()) {
		cout << answer.top() << '\n';
		answer.pop();
	}

	return 0;
}
