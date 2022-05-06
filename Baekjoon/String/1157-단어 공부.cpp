#include <iostream>
#include <map>
using namespace std;

int max_v = 0, cnt = 0;
char ans;
string in_word;
map<char, int> word_list;
void make_input() {
	cin >> in_word;
}

void count_word() {
	for (int i = 0; i < in_word.size(); i++) word_list[in_word[i]] += 1;
}

void to_capital() {
	for (int i = 0; i < in_word.size(); i++) {
		if ('a' <= in_word[i] && in_word[i] <= 'z') in_word[i] -= 32;
	}
}

void find_ans() {
	for (auto i : word_list) {
		if (i.second > max_v) {
			max_v = i.second;
			ans = i.first;
		}
	}

	for (auto i : word_list) {
		if (i.second == max_v) cnt++;
	}

	if (cnt > 1) cout << "?";
	else cout << ans;
}

int main(void) {

	make_input();
	to_capital();
	count_word();
	find_ans();
	
	return 0;
}
