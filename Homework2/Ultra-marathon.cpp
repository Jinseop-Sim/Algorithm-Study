#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int v = 0, e = 0, max_sum = 0;
vector<vector<char>> marathon_map(26, vector<char>());
vector<vector<int>> dist_map(26, vector<int>(26, 0));
vector<bool> visit(26, 0);
vector<char> my_stack;

bool prunning(char start) {
	queue<int> q;
	vector<bool> bfs_visit(26, 0);
	bool is_end = false;
	q.push(start);
	bfs_visit[start - 'a'] = true;
	while (!q.empty()) {
		start = q.front() - 'a';
		q.pop();
		for (int i = 0; i < marathon_map[start].size(); i++) {
			if (!visit[marathon_map[start][i] - 'a']) {
				if (!bfs_visit[marathon_map[start][i] - 'a']) {
					q.push(marathon_map[start][i]);
					if (marathon_map[start][i] == 'a') { is_end = true; break; }
					bfs_visit[marathon_map[start][i] - 'a'] = true;
				}
			}
		}
		if (is_end) break;
	}

	if (q.empty()) return 0;
	else return 1;
}

void backtrack(int src, int sum) {
	if (!my_stack.empty() && my_stack[my_stack.size() - 1] == 'a') {
		if (max_sum < sum) max_sum = sum;
		return;
	}

	if (src != 0) {
		if (prunning(char(src + 'a')) == 0) return;
	}

	for (int i = 0; i < marathon_map[src].size(); i++) {
		if (!visit[marathon_map[src][i] - 'a']) {
			sum += dist_map[src][marathon_map[src][i] - 'a'];
			visit[marathon_map[src][i] - 'a'] = true;
			my_stack.push_back(marathon_map[src][i]);
			backtrack(marathon_map[src][i] - 'a', sum);
			my_stack.pop_back();
			sum -= dist_map[src][marathon_map[src][i] - 'a'];
			visit[marathon_map[src][i] - 'a'] = false;
		}
	}
}

int main() {
	char temp_x, temp_y;
	int dist = 0;
	cin >> v >> e;

	for (int i = 0; i < e; i++) {
		cin >> temp_x >> temp_y >> dist;
		marathon_map[temp_x - 'a'].push_back(temp_y);
		marathon_map[temp_y - 'a'].push_back(temp_x);
		dist_map[temp_x - 'a'][temp_y - 'a'] = dist;
		dist_map[temp_y - 'a'][temp_x - 'a'] = dist;
	}

	backtrack(0, 0);
	cout << max_sum;
}
