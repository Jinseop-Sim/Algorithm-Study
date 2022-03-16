#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
	int n1 = 0, n2 = 0, time = 0, cnt = 0;
	char ants;
	deque<pair<char, bool>> ways;

	cin >> n1 >> n2;
	for (int i = 0; i < n1; i++) {
		cin >> ants;
		ways.push_front(make_pair(ants, true));
	}
	for (int i = 0; i < n2; i++) {
		cin >> ants;
		ways.push_back(make_pair(ants, false));
	}
	
	cin >> time;
	while (time != cnt) {
		for (int i = 0; i < ways.size() - 1; i++) {
			if (ways[i].second == true && ways[i + 1].second == false) { // 둘의 진행 방향이 같으면 1칸만 건너뛰기.
				swap(ways[i], ways[i + 1]); // 둘의 진행 방향이 다르면 한 칸 더 건너뛰어서 찾기.
				i++;
			}
		}
		cnt++;
	}

	for (auto i : ways) cout << i.first;
	return 0;
}
