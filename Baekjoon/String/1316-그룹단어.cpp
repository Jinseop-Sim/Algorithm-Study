#include <iostream>
#include <map>
using namespace std;

int num = 0, cnt = 0;
map<char, int> word_list;

int main(void) {
	cin >> num;
	for (int i = 0; i < num; i++) {
		word_list.clear();
		string temp;
		cin >> temp;
		if (temp.size() == 1) cnt++;
		word_list[temp[0]] += 1;
		for (int j = 1; j < temp.size(); j++) {
			if (temp[j - 1] == temp[j]) {}
			else {
				if (word_list[temp[j]] != 0) break;
				else word_list[temp[j]] += 1;
			}
			if (j == temp.size() - 1) cnt++;
		}
	}

	cout << cnt;
	return 0;
}
