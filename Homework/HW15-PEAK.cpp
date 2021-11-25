#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct cmp {
	bool operator()(pair<int, int> &a, pair<int, int> &b) {
		return a.second > b.second;
	}
};
vector<pair<int, int>> code_pair;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> for_vec;
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> code_list;
void clear_queue() {
	while (!code_list.empty()) code_list.pop();
}
void insert_section(int n, int b, int e) {
	for (int i = 0; i < n; i++) {
		cin >> b >> e;
		for_vec.emplace(b, e);
	}
	while (!for_vec.empty()) {
		code_pair.push_back(for_vec.top());
		for_vec.pop();
	}

}
int calc_max() {
	int solution = 0;
	for (int i = 0; i < code_pair.size(); i++) {
		while (!code_list.empty() && code_list.top().second <= code_pair[i].first) code_list.pop();
		code_list.push(code_pair[i]);
		if (code_list.size() >= solution) {
			solution = code_list.size();
		}
	}
	return solution;
}
void find_answer(int max_cnt) {
	int solution = 0, diff = 0;
	pair<int, int> answer;
	vector<pair<int, int>> answer_list;
	for (int i = 0; i < code_pair.size(); i++) {
		while (!code_list.empty() && code_list.top().second <= code_pair[i].first) code_list.pop();
		code_list.push(code_pair[i]);
		if (code_list.size() >= solution) {
			solution = code_list.size();
			answer = { code_pair[i].first, code_list.top().second };
			if (solution == max_cnt) answer_list.push_back(answer);
		}
	}
	for (int i = 0; i < answer_list.size(); i++) {
		if (answer_list[i].second - answer_list[i].first >= diff) {
			diff = answer_list[i].second - answer_list[i].first;
			answer = { answer_list[i].first, answer_list[i].second };
		}
	}
	cout << answer.first << " " << answer.second;
}
int main(void) {
	int n = 0, b = 0, e = 0, max_cnt = 0;
	cin >> n;
	insert_section(n, b, e);
	max_cnt = calc_max();
	clear_queue();
	find_answer(max_cnt);
	return 0;
}
