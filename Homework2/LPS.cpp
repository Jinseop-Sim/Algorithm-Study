// 최장 회문 부순서 문제이다.

#include <iostream>
#include <vector>
using namespace std;

int main() {
	string code;
	cin >> code;
	int code_size = code.length();

	vector<vector<string>> DP(code_size, (vector<string>(code_size))); // 최장 회문의 길이는 숫자로 만들면 되지만, 출력을 해야하는데 어떡하나?
									   // 문자열을 배열에 집어넣어버린다!
	for (int i = 0; i < code_size; i++) {
		DP[i][i] = code[i];
	}

	for (int k = 1; k < code_size; k++) {
		for (int i = 0, j = i + k; j < code_size; i++, j++) {
			if (code[i] == code[j]) DP[i][j] = code[i] + DP[i + 1][j - 1] + code[j]; // 짝이 맞는 경우에는, 양 쪽 끝에 문자열을 붙이며 나아간다.
			else {
				if (DP[i + 1][j].size() > DP[i][j - 1].size()) DP[i][j] = DP[i + 1][j]; // 둘이 길이가 다를 땐, 길이가 더 긴 것을 택한다.
				else if(DP[i +1][j].size() < DP[i][j - 1].size()) DP[i][j] = DP[i][j - 1];
				else {
					if (DP[i + 1][j] >= DP[i][j - 1]) DP[i][j] = DP[i][j - 1]; // 둘이 길이가 같을 땐, 사전순으로 빠른 것을 고른다.
					else DP[i][j] = DP[i + 1][j];
				}
			}
		}
	}

	cout << DP[0][code_size - 1];
}
