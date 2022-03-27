#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

map<int, pair<int, int>> rank_info;
vector<int> names;
void get_input(int n) {
	for (int i = 0; i < n; i++) {
		int c, g, s, b, score;
		cin >> c >> g >> s >> b;
		names.push_back(c);
		score = g * 100000 + s * 100 + b;
		rank_info[c] = make_pair(score, 1);
	}
}

void make_rank(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (rank_info[names[i]].first < rank_info[names[j]].first) rank_info[names[i]].second++;
		}
	}
}

int main() {
	int n, k;
	cin >> n >> k;
	
	get_input(n);
	make_rank(n);

	cout << rank_info[k].second;
	return 0;
}
