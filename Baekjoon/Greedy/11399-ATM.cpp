#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> p_queue;
int sum = 0, part_sum = 0;

void calc() {
	while (!p_queue.empty()) {
		part_sum += p_queue.top();
		sum = sum + part_sum;
		p_queue.pop();
	}
}

int main() {
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp = 0;
		cin >> temp; p_queue.push(temp);
	}
	calc();
	cout << sum;
}
