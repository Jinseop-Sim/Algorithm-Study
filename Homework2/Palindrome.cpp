#include <iostream>
#include <vector>
using namespace std;

void make_base(string sentence, vector<vector<string>>& DP) {
	for (int i = 0; i < sentence.length(); i++) {
		DP[i][i] = sentence[i];
	}
}

void make_palindrome(string sentence, vector<vector<string>>& DP) {
	for (int k = 1; k < sentence.length(); k++) {
		for (int i = 0, j = i + k; j < sentence.length(); i++, j++) {
			if (sentence[i] == sentence[j]) DP[i][j] = sentence[i] + DP[i + 1][j - 1] + sentence[j];
			else {
				if (DP[i + 1][j].size() > DP[i][j - 1].size()) DP[i][j] = DP[i + 1][j];
				else if (DP[i + 1][j].size() < DP[i][j - 1].size()) DP[i][j] = DP[i][j - 1];
				else {
					if (DP[i + 1][j] >= DP[i][j - 1]) DP[i][j] = DP[i][j - 1];
					else DP[i][j] = DP[i + 1][j];
				}
			}
		}
	}
}

int main() {
	string sentence;
	cin >> sentence;
	vector<vector<string>> DP(sentence.length(), (vector<string>(sentence.length())));

	make_base(sentence, DP);
	make_palindrome(sentence, DP);

	cout << DP[0][sentence.length()-1];
}

// 동적 계획법을 이용한 LPS 문제이다.
// 최장 회문 부순서.
