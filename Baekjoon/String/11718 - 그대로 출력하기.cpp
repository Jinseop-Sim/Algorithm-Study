#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string word;
	while (true) {
		getline(cin, word);
		if (word == "") break;
		cout << word << '\n';
	}
	return 0;
}

// getline의 사용법을 알 수 있었다.
