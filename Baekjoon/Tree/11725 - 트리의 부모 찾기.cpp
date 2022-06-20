#include <iostream>
#include <vector>
using namespace std;
#define MAX 100001

int n = 0;
vector<vector<int>> adj_list(MAX);
int parents[MAX] = { 0, };
bool visit[MAX] = { 0, };

void dfs(int root) {

	visit[root] = true;

	for (int i = 0; i < adj_list[root].size(); i++) {
		int next_node = adj_list[root][i];
		if (!visit[next_node]) {
			parents[next_node] = root; // DFS로 Graph를 순회하는데, 들어가기 이전 Node가 바로 Parent가 됩니다.
			dfs(next_node); // Parent를 배열의 각 Index에 저장하며 내려갑니다.
		}
	}
}

int main(void) {
	cin >> n;

	for (int i = 0; i < n - 1; i++) { // 연결된 Node들은 Adjacent List로 구현합니다.
		int u, v;
		cin >> u >> v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}

	dfs(1);

	for (int i = 2; i <= n; i++) cout << parents[i] << '\n';
	return 0;
}
