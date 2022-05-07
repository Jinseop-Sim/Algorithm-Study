#include <iostream>
#include <stack>
using namespace std;

int num = 0;
int main(void) {
	cin >> num;
	for (int i = 0; i < num; i++) {
		stack<char> parens;
		string temp;
		cin >> temp;
		for (int j = 0; j < temp.size(); j++) {
			if (temp[j] == '(') parens.push(temp[j]);
			if (temp[j] == ')') {
				if (parens.size() == 0) parens.push(temp[j]);
				if (parens.top() == '(') parens.pop();
				else continue;
			}
		}
		if (parens.size() == 0) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}

// Stack의 특성을 이용해서 ()이 완성될 시에 POP을 해준다.
// 그 작업 이후에 Stack내에 뭔가 남아있으면, 그것은 불완전 괄호.
