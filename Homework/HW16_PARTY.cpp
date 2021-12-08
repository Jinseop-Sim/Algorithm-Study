#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<char>> city_map(26);
vector<int> visit_didier(26, -1);
vector<int> visit_eric(26, -1);
vector<int> visit_dmitrij(26, -1);
void make_list(int n) {
	for (int i = 0; i < n; i++) {
		vector<char> temp;
		char city = '0';
		while (city != '$') {
			cin >> city;
			if (city != '$') temp.push_back(city);
		}
		for (int i = 1; i < temp.size(); i++) city_map[(int)temp[0] - 97].push_back(temp[i]);
	}
}
void BFS(char start, int who) {
	queue<int> q;
	q.push(start);
	switch (who) {
		case 0: 
			visit_didier[(int)start - 97] = 0;
			break;
		case 1:
			visit_eric[(int)start - 97] = 0;
			break;
		case 2:
			visit_dmitrij[(int)start - 97] = 0;
			break;
	}

	while(!q.empty()){
		char temp = q.front();
		q.pop();
		for(int i = 0; i < city_map[(int)temp-97].size(); i++){
			char next = city_map[(int)temp - 97][i];
			switch (who) {
				case 0:
					if (visit_didier[(int)next - 97] == -1) {
						q.push(next);
						visit_didier[(int)next - 97] = visit_didier[(int)temp - 97] + 1;
					}
					break;
				case 1:
					if (visit_eric[(int)next - 97] == -1) {
						q.push(next);
						visit_eric[(int)next - 97] = visit_eric[(int)temp - 97] + 1;
					}
					break;
				case 2:
					if (visit_dmitrij[(int)next - 97] == -1) {
						q.push(next);
						visit_dmitrij[(int)next - 97] = visit_dmitrij[(int)temp - 97] + 1;
					}
					break;
			}
		}
	}
}
void find_answer() {
	vector<int> temp_max;
	vector<char> answer_list;
	for (int j = 0; j < visit_didier.size(); j++) {
		temp_max.push_back(max({ visit_didier[j], visit_eric[j], visit_dmitrij[j]}));
	}
	int min_v = 100;
	for (int k = 0; k < temp_max.size(); k++) {
		if (temp_max[k] != -1) {
			if (temp_max[k] < min_v) min_v = temp_max[k];
		}
	}
	for (int k = 0; k < temp_max.size(); k++) {
		if (temp_max[k] == min_v) {
			answer_list.push_back((char)k + 'a');
		}
	}
	sort(answer_list.begin(), answer_list.end());
	int answer_dist = 1 + 3 * (temp_max[(int)answer_list[0] - 97] - 1);
	if (temp_max[(int)answer_list[0] - 97] == 0) cout << '@' << endl << -1;
	else cout << answer_list[0] << endl << answer_dist;
}
int main() {
	int n;
	cin >> n;
	vector<char> friends(3, '0');
	cin >> friends[0] >> friends[1] >> friends[2];
	make_list(n);
	for (int i = 0; i < friends.size(); i++) BFS(friends[i], i);
	find_answer();
	return 0;
}
