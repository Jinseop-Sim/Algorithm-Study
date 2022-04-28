#include <iostream>
#include <vector>
using namespace std;

int n = 0, e = 0, res = 0;

void dfs(int start, vector<vector<int>> compu_maps, vector<bool>& visit) {
	visit[start] = true;
	for (int i = 0; i < n; i++) {
		if (compu_maps[start][i] && !visit[i]) {
			dfs(i, compu_maps, visit);
			res++;
		}
	}
}

int main() {
	int temp_x = 0, temp_y = 0;
	cin >> n >> e;
	vector<vector<int>> compu_maps(n, vector<int>(n, 0));
	vector<bool> visit(n, 0);
	for (int i = 0; i < e; i++) {
		cin >> temp_x >> temp_y;
		compu_maps[temp_x - 1][temp_y - 1] = 1;
		compu_maps[temp_y - 1][temp_x - 1] = 1;
	}

	dfs(0, compu_maps, visit);
	cout << res;
}
