// 전형적인 BFS 최단거리 문제였다.
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<char>> forest_map;
queue<pair<int, int>> hedgehog;
queue<pair<int, int>> water;
pair<int, int> beaver_house;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
bool is_found = false;

void spread_water(int r, int c) {
	int num = water.size();
	for (int i = 0; i < num; i++) { // 물이 시작하는 곳이 몇 군데인지 돌리는 for loop
		int current_water_x = water.front().first;
		int current_water_y = water.front().second;

		water.pop(); // 이전 물의 위치는 queue에서 pop

		for (int j = 0; j < 4; j++) {
			int nx = current_water_x + dx[j];
			int ny = current_water_y + dy[j];

			if ((0 <= nx && nx < r) && (0 <= ny && ny < c) && (forest_map[nx][ny] == '.')) {
				water.push(make_pair(nx, ny)); // 다음 물의 위치가 queue에 저장
				forest_map[nx][ny] = '*';
			}
		}
	}
}

void move_hedgehog(int r, int c, int& time) {
	int num = hedgehog.size();
	for (int i = 0; i < num; i++) { // 고슴도치가 몇 마리인지 돌리는 for loop
		int current_hedgehog_x = hedgehog.front().first;
		int current_hedgehog_y = hedgehog.front().second;

		hedgehog.pop();

		for (int j = 0; j < 4; j++) {
			int nx = current_hedgehog_x + dx[j];
			int ny = current_hedgehog_y + dy[j];

			if (nx == beaver_house.first && ny == beaver_house.second) {
				time++; is_found = true;
				cout << time;
				return;
			}

			if ((0 <= nx && nx < r) && (0 <= ny && ny < c) && (forest_map[nx][ny] == '.')) {
				hedgehog.push(make_pair(nx, ny));
				forest_map[nx][ny] = 'S';
			}
		}
	}
}

void read_map(int r, int c) {
	for (int i = 0; i < r; i++) {
		vector<char> temp;
		char entity;
		for (int j = 0; j < c; j++) {
			cin >> entity;
			if (entity == 'S') hedgehog.push(make_pair(i, j));
			if (entity == '*') water.push(make_pair(i, j));
			if (entity == 'D') beaver_house = make_pair(i, j);
			temp.push_back(entity);
		}
		forest_map.push_back(temp);
	}
}

void find_shortest_path(int r, int c) {
	int time = 0;

	while (!hedgehog.empty()) {
		spread_water(r, c); // 물을 먼저 이동시킨 뒤
		move_hedgehog(r, c, time); // 고슴도치를 이동시켜야 고슴도치가 물로 못 간다.
		if (is_found) return;
		time++;
	}
	cout << "KAKTUS";
	return;
}

int main() {
	int r, c;
	cin >> r >> c;

	read_map(r, c);
	find_shortest_path(r, c);

	return 0;
}
