#include <iostream>
#include <vector>
using namespace std;
#define MAXL 5

vector<string> strings;
int search_max() {
	int max_length = 0;
	for (int i = 0; i < strings.size(); i++) {
		if (max_length < strings[i].size()) max_length = strings[i].size();
	}
	return max_length;
}

void print_vertical(int max_length) {
	for (int i = 0; i < max_length; i++) {
		for (int j = 0; j < MAXL; j++) {
			if (strings[j].size() <= i) continue;
			cout << strings[j][i];
		}
	}
}

int main() {
	int iter = 0;
	string sentence;
	for (int i = 0; i < MAXL; i++) {
		cin >> sentence;
		strings.push_back(sentence);
	}
	int max_length = search_max();
	print_vertical(max_length);

	return 0;
}
