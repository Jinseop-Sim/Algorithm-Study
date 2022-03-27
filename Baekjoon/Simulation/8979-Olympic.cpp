#include <iostream>
#include <string>
#include <map>
using namespace std;

map<int, pair<int, int>> rank_info;
void get_input(int n) {
	for (int i = 0; i < n; i++) {
		int c;
		string g, s, b, info;
		cin >> c >> g >> s >> b;
		info = g + s + b;
		rank_info[c] = make_pair(stoi(info), 1);
	}
}

void make_rank(int n) {
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (rank_info[i].first < rank_info[j].first) rank_info[i].second++;
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
