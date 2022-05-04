#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int v = 0, e = 0, start = 0;
queue<int> bfs_q;

void refresh(vector<bool>& visit) {
	for (int i = 0; i < visit.size(); i++) visit[i] = 0;
}

void dfs(int start, vector<vector<bool>>& maps, vector<bool>& visit) {
	visit[start] = true;
	cout << start << " ";

	for (int i = 1; i <= v; i++) {
		if (maps[start][i] && !visit[i]) dfs(i, maps, visit);
	}
}

void bfs(int start, vector<vector<bool>>& maps, vector<bool>& visit) {
	bfs_q.push(start);
	visit[start] = true;
	cout << start << " ";

	while (!bfs_q.empty()) {
		start = bfs_q.front();
		bfs_q.pop();

		for (int i = 1; i <= v; i++) {
			if (maps[start][i] && !visit[i]) {
				bfs_q.push(i);
				visit[i] = true;
				cout << i << " ";
			}
		}
	}
}

int main(void) {
	int temp_x, temp_y;
	cin >> v >> e >> start;
	vector<vector<bool>> maps(v+1, (vector<bool>(v+1, 0)));
	vector<bool> visit(v+1, 0);

	for (int i = 0; i < e; i++) {
		cin >> temp_x >> temp_y;
		maps[temp_x][temp_y] = maps[temp_y][temp_x] = true;
	}

	dfs(start, maps, visit);
	cout << endl;
	refresh(visit);
	bfs(start, maps, visit);
}
