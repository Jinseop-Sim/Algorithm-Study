#include <iostream>
using namespace std;

int temp;
string word;
int main(void) {
	cin >> word;

	for (int i = 0; i < word.size(); i++) {
		temp = word[i] - 'A';
		temp -= 3;
		if (temp < 0) temp += 26;
		word[i] = temp + 'A';
	}

	cout << word;
	return 0;
}
