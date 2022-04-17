#include <iostream>
#include <queue>
using namespace std;

struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.first > b.first;
	}
};

priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> table;
priority_queue<int, vector<int>, greater<int>> room;
int main() {
	int n = 0, s = 0, e = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		pair<int, int> temp;
		cin >> s >> e; 
		table.push(make_pair(s, e));
	}

	room.push(table.top().second);
	while (true) {
		table.pop();
		if (table.empty()) break;
		room.push(table.top().second);
		if (table.top().first >= room.top()) room.pop();
	}

	cout << room.size();
}
