#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int num = 0, temp = 0;
stack<int> oken;
vector<int> seq;

void find_oken(vector<int>& ans) {
	for (int i = num - 1; i >= 0; i--) { // 내가 입력한 배열을 "뒤에서 부터" 탐색한다.
		while (!oken.empty() && oken.top() <= seq[i]) oken.pop(); // 현재 내가 탐색하려는 수보다 큰 수가 Stack에서 등장할 때 까지 Pop한다.

		if (oken.empty()) ans[i] = -1; // 만약 Stack이 비어있다면? 현재 나보다 큰 수가 없다는 것!
		else ans[i] = oken.top(); // Stack이 비어있지 않다면 나보다 큰 수를 답에 넣으면 된다.
                              // 왜냐하면, Stack에서 계속 Pop을 하면서 제일 먼저 등장하는 큰수가 가장 왼쪽에 있는 수가 되니까!
		oken.push(seq[i]); // 여기서 배열에 있는 수를 뒤에서 부터 차곡차곡 넣는다.
                       // 뒤에서 부터 넣어야, Pop하다가 제일 먼저 나오는 큰 수가 제일 왼쪽에 있는 수가 된다!
	}
}

int main() {
	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> temp;
		seq.push_back(temp);
	}

	vector<int> ans(num, 0);
	find_oken(ans);

	for (auto i : ans) cout << i << " ";
}
