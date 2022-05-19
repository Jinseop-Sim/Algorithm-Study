#include <iostream>
#include <queue>
using namespace std;

int n = 0, m = 0;
int maps[101][101]; // 지도이다.
int visit[101][101]; // 방문했는지 안했는지 저장할 배열이다.
int cnt[101][101]; // 앞으로 전진하면서 몇 칸을 움직였는지 저장할 배열이다.

int dx[4] = { 1, -1, 0, 0 }; // 좌, 우
int dy[4] = { 0, 0, 1, -1 }; // 상, 하
queue<pair<int, int>> q;

void bfs() {
	visit[0][0] = true; // 시작점을 방문했다.
	q.push(make_pair(0, 0)); // Queue에 시작점 좌표를 집어 넣는다.
	cnt[0][0]++; // 시작점을 1칸으로 친다.

	while (!q.empty()) {
		int x = q.front().first; // x좌표
		int y = q.front().second; // y좌표
		q.pop(); // 좌표를 저장한 후 방문했던 정점을 뽑아낸다.

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i]; // 상하좌우로 이동할 수 있는 좌표
			int ny = y + dy[i];
			if ((nx >= 0 && nx < n) && (ny >= 0 && ny < m)) { // 지도 밖으로 나가지 않는 선에서
				if (!visit[nx][ny] && maps[nx][ny] == 1) { // 방문한 적이 없고 길인 곳으로 이동한다.
					visit[nx][ny] = true; // 방문했다고 바꿔주고
					q.push(make_pair(nx, ny)); // Queue에서 뽑아냈던 정점과 이어진 정점들이므로, Queue에 집어 넣는다.
					cnt[nx][ny] = cnt[x][y] + 1; // 내가 이동하는 곳으로 걸음 수를 추가한다.
				}
			}
		}
	}
}

int main() {
	cin >> n >> m;
	vector<vector<bool>> visit(n, vector<bool>(m, 0));

	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < m; j++) maps[i][j] = temp[j] - '0';
	}

	bfs();
	cout << cnt[n - 1][m - 1];

	return 0;
}

// 대표적인 BFS문제이다.
