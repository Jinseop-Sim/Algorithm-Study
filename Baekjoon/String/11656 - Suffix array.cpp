#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> printer;
int main(void) {
	string word;
	cin >> word;

	for (int i = 0; i < word.size(); i++) {
		string temp;
		for (int j = i; j < word.size(); j++) {
			temp += word[j];
		}
		printer.push_back(temp);
	}

	sort(printer.begin(), printer.end());
	for (auto i : printer) {
		cout << i << '\n';
	}

	return 0;
}
