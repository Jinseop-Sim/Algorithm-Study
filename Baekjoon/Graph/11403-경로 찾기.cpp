#include <iostream>
#include <vector>
using namespace std;

int v = 0;

void dfs(int start, vector<bool>& visit, vector<vector<int>>& matri_x) {
	for (int i = 0; i < v; i++) {
		if (!visit[i] && matri_x[start][i]) { // 방문이 가능한 정점이면서 방문을 아직 안했다면, 입장한다.
			visit[i] = true; // 입장하면서 Visit을 1로 바꾸어 놓고 입장한다.
			dfs(i, visit, matri_x); // 입장.
		}
	}
}

int main() {
	cin >> v;
	vector<vector<int>> matri_x(v, vector<int>(v, 0));

	for (int i = 0; i < v; i++) {
		for (int j = 0; j < v; j++) {
			cin >> matri_x[i][j]; // 방향이 있는 Graph기 때문에 한번만 1로 바꿔준다.
		}
	}

	for (int i = 0; i < v; i++) {
		vector<bool> visit(v, 0); // 현재 정점에서 방문 가능한 모든 정점을 출력할 것이다.
		dfs(i, visit, matri_x); // 따라서 매 정점마다 visit을 따로따로 매번 출력해준다.
		for (int j = 0; j < v; j++) {
			cout << visit[j] << " ";
		}
		cout << endl;
	}
}
