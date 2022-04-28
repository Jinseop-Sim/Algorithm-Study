#include <iostream>
#include <vector>
using namespace std;

int v = 0;

void dfs(int start, vector<bool>& visit, vector<vector<int>>& matri_x) {

	for (int i = 0; i < v; i++) {
		if (!visit[i] && matri_x[start][i]) {
			visit[i] = true;
			dfs(i, visit, matri_x);
		}
	}
}
int main() {
	cin >> v;
	vector<vector<int>> matri_x(v, vector<int>(v, 0));

	for (int i = 0; i < v; i++) {
		for (int j = 0; j < v; j++) {
			cin >> matri_x[i][j];
		}
	}

	for (int i = 0; i < v; i++) {
		vector<bool> visit(v, 0);
		dfs(i, visit, matri_x);
		for (int j = 0; j < v; j++) {
			cout << visit[j] << " ";
		}
		cout << endl;
	}
}
