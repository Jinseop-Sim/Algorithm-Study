#include <iostream>
#include <queue>
using namespace std;

int num = 0, op = 0;
priority_queue<int> oper;
int main(void) {
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> op;
		switch (op) {
		case 0:
			if (oper.empty()) cout << 0 << '\n';
			else {
				cout << oper.top() << '\n';
				oper.pop();
			}
			break;
		default:
			oper.push(op);
			break;
		}
	}
	return 0;
}
