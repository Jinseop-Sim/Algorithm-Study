#include <iostream>
#include <set>
#include <vector>
using namespace std;

vector<string> s_group;
vector<set<string>> substrings;
void store_sentece(int n) {
	string sentence;
	for (int i = 0; i < n; i++) {
		string temp;
		while (true) {
			cin >> sentence;
			if (sentence.compare("$") == 0) break;
			int nn = sentence.size();
			for (int i = 0; i < nn; i++) {
				if ((sentence[i] & 0x80) != 0)	temp.push_back(sentence[i]);
			}
		}
		s_group.push_back(temp);
	}
}
void make_substrings() {
	for (int i = 0; i < s_group.size(); i++) {
		set<string> temp;
		if (s_group[i].size() == 0) { temp.insert(s_group[i]); }
		else {
			for (int j = 0; j < s_group[i].size() - 2; j += 2) {
				temp.insert(s_group[i].substr(j, 4));
			}
		}
		substrings.push_back(temp);
	}
}
void compare_plagiarism() {
	pair<int, int> plagi_idx;
	double length_a = 0, length_b = 0, fin_length = 0;
	double plagi_ratio = 0, max_ratio = 0;
	for (int i = 0; i < substrings.size(); i++) {
		set<string> temp;
		length_a = substrings[i].size();
		for (int j = i+1; j < substrings.size(); j++) {
			length_b = substrings[j].size();
			if (length_a == 1 || length_b == 1) continue;
			temp.insert(substrings[i].begin(), substrings[i].end());
			temp.insert(substrings[j].begin(), substrings[j].end());
			fin_length = temp.size();
			plagi_ratio = (length_a + length_b - fin_length) / (length_a + length_b);
			if (max_ratio < plagi_ratio) {
				max_ratio = plagi_ratio;
				plagi_idx.first = i+1; plagi_idx.second = j+1;
			}
			temp.clear();
		}
	}
	cout << plagi_idx.first << " " << plagi_idx.second;
}
int main() {
	int n;
	cin >> n;
	store_sentece(n);
	make_substrings();
	compare_plagiarism();
	return 0;
}
