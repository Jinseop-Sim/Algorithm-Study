#include <iostream>
#include <string>
using namespace std;

string word;
int cnt = 1;
int main() {
	getline(cin, word);
	
	for (int i = 0; i < word.length(); i++) {
		if (word[i] == ' ') cnt++;
	}
	if (word[0] == ' ') cnt--;
	if (word[word.length() - 1] == ' ') cnt--;

	cout << cnt;
	return 0;
}

// 음.. 공백의 수를 모두 센 다음 앞 뒤만 빼준다.
