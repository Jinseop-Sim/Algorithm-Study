#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

void make_loaf(vector<int> breads, int& cnt) {
	for (int i = 0; i < breads.size(); i++) {
		if (i == 0) {
			if (abs(breads[i]) != i + 1) {
				if (abs(breads[i]) - abs(breads[i + 1]) != 1) cnt += 1;
				else if (breads[i] * breads[i + 1] < 0) cnt += 1;
			}
		}
		else {
			if (abs(breads[i]) != i + 1) {
				if (abs(breads[i - 1]) - abs(breads[i]) != 1) cnt += 1;
				else if (breads[i] * breads[i - 1] < 0) cnt += 1;
			}
		}
	}
}

void count_unary(vector<int> breads, int& cnt) {
	if (breads[0] != 1) cnt += 1;
	for (int i = 0; i < breads.size(); i++) {
		if (breads[i] < 0) {
			if (i == breads.size() - 1) {
				if (abs(breads[i]) - abs(breads[i - 1]) == 1) cnt += 1; continue;
			}
			if (abs(breads[i + 1]) - abs(breads[i]) == 1) cnt += 1;
		}
	}
}

void say_answer(int cnt) {
	switch (cnt) {
	case 1:
		cout << "one" << endl;
		break;
	case 2:
		cout << "two" << endl;
		break;
	default:
		cout << "over" << endl;
		break;
	}
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < 5; i++) {
		vector<int> breads;
		int bread, cnt = 0;

		for (int j = 0; j < n; j++) {
			cin >> bread;
			breads.push_back(bread);
		}

		make_loaf(breads, cnt);
		count_unary(breads, cnt);

		say_answer(cnt);
	}

	return 0;
}
