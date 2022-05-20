#include <iostream>
#include <vector>
#include <deque>
using namespace std;

deque<int> rot_queue;
vector<int> pos;

void init_queue(int n) {
	for (int i = 1; i < n + 1; i++) rot_queue.push_back(i);
}

void init_pos(int m) {
	for (int i = 0; i < m; i++) {
		int temp; cin >> temp;
		pos.push_back(temp);
	}
}

void rot_left() {
	rot_queue.push_back(rot_queue.front());
	rot_queue.pop_front();
}

void rot_right() {
	rot_queue.push_front(rot_queue.back());
	rot_queue.pop_back();
}

int rot_count(int m) {
	int cnt = 0;

	for (int i = 0; i < m; i++) {
		int idx = 0;
		for (int j = 0; j < rot_queue.size(); j++) {
			if (pos[i] == rot_queue[j]) { idx = j; break; }
		}

		if (idx < rot_queue.size() - idx) {
			while (true) {
				if (pos[i] == rot_queue.front()) { rot_queue.pop_front(); break; }
				rot_left(); cnt++;
			}
		}
		else {
			while (true) {
				if (pos[i] == rot_queue.front()) { rot_queue.pop_front(); break; }
				rot_right(); cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	int n = 0, m = 0, cnt = 0;
	cin >> n >> m;

	init_queue(n);
	init_pos(m);

	cout << rot_count(m);
	return 0;
}

// Issue : 35번 조건문을 idx < deque.size()/2 로 하면 답이 나오지 않는다. 왜 그럴까?
// Deque의 Size가 홀수일 경우에는 int / 2 연산으로 계산할 경우 잘못 연산하는 경우가 발생한다.
