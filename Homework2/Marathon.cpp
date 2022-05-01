#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int v = 0, e = 0, res_count = 0;
vector<vector<char>> marathon_map(26, vector<char>());
vector<vector<int>> dist_map(26, vector<int>(26, 0));
vector<bool> visit(26, 0);
vector<char> my_stack;
vector<string> res_list;

bool compare(string a, string b) {
	if (a.length() == b.length()) return a < b;
	return a.length() > b.length();
}

void make_result() {
	string temp;
	for (int i = 0; i < my_stack.size() - 1; i++) temp += my_stack[i];
	res_list.push_back(temp);
}

void backtrack(int src, int sum) {
	if (!my_stack.empty() && my_stack[my_stack.size() - 1] == 'a') {
		if (sum == 42) {
			make_result();
			res_count++;
			return;
		}
		else return; 
	}
	else if (sum > 42) return;

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
	sort(res_list.begin(), res_list.end(), compare);

	if (res_count == 0) cout << "None";
	else {
		cout << res_list[0].size() + 1 << endl;
		cout << "a ";
		for (auto i : res_list[0]) cout << i << " ";
	}
}
