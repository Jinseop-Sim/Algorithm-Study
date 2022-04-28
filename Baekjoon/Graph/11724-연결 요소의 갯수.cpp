#include <iostream>
#include <vector>
using namespace std;

int v = 0, e = 0, res = 0;

void make_map(vector<vector<int>>& maps) {
	int temp_x = 0, temp_y = 0;
	for (int i = 0; i < e; i++) {
		cin >> temp_x >> temp_y;
		maps[temp_x - 1][temp_y - 1] = 1;
		maps[temp_y - 1][temp_x - 1] = 1;
	}
}

// DFS 함수의 Vector 부분에 Ampersand를 넣지 않으면 dfs가 재귀를 돌 때 마다 새 Vector을 만들기 때문에 Memory 초과가 발생한다.
void dfs(int start, vector<vector<int>>& maps, vector<bool>& visit) {
	visit[start] = true;
	for (int i = 0; i < v; i++) {
		if (maps[start][i] && !visit[i]) dfs(i, maps, visit);
	}
}

int main() {
	cin >> v >> e;
	vector<vector<int>> maps(v, vector<int>(v, 0));
	vector<bool> visit(v, 0);

	make_map(maps);
	for (int i = 0; i < v; i++) {
		if (!visit[i]) {
			dfs(i, maps, visit);
			res++;
		}
	}

	cout << res;
}
