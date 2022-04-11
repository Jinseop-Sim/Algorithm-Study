#include <iostream>
#include <queue>
using namespace std;

queue<int> kill_queue;

void init_queue(int n) {
	for (int i = 0; i < n; i++) kill_queue.push(i + 1);
}

void rot_left() {
	kill_queue.push(kill_queue.front());
	kill_queue.pop();
}

void josephus(int k) {
	while (!kill_queue.empty()) {
		for (int i = 0; i < k - 1; i++) rot_left();
		if (kill_queue.size() == 1) cout << kill_queue.front();
		else cout << kill_queue.front() << ", ";
		kill_queue.pop();
	}
}
int main() {
	int n = 0, k = 0;
	cin >> n >> k;

	init_queue(n);
	
	cout << "<";
	josephus(k);
	cout << ">";
	return 0;
}

// Queue를 사용하는 대표적인 문제인 요세푸스 문제였다.
