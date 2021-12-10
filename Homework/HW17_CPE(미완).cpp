#include <iostream>
#include <set>
#include <vector>
#define KMER 4
using namespace std;

vector<vector<char>> s_group;
vector<vector<string>> substrings;
void store_sentece(int n) {
	for (int i = 0; i < n; i++) {
		char sentence = '0';
		vector<char> temp;
		while (sentence != '$') {
			cin >> sentence;
			if ((int)sentence < 0 || (int)sentence > 126) {
				temp.push_back(sentence);
			}
		}
		s_group.push_back(temp);
	}
}

void make_substring() {
	string temp;
	for (int i = 0; i < s_group.size(); i++) {
		int iter = 0;
		vector<string> temp_sub;
		while (true) {
			temp.push_back(s_group[i][iter]);
			if (temp.size() == KMER) {
				temp_sub.push_back(temp); 
				temp.clear();
				if (iter == s_group[i].size()-1) break;
				iter--;
				continue;
			}
			iter++;
		}
		substrings.push_back(temp_sub);
	}
}

void check_plagiarism(pair<int, int> &plagi_idx) {
	set<string> solution;
	int iter = 0, cmp_iter = 0;
	double plagi = 0.0, max_plagi = 0.0;
	while (true) {
		if (iter == substrings.size()) break;
		if (cmp_iter == substrings.size()) {
			iter++; cmp_iter = iter; continue;
		}
		if (iter == cmp_iter) { cmp_iter++; continue; }
		for (int i = 0; i < substrings[iter].size(); i++) {
			solution.insert(substrings[iter][i]);
		}
		for (int k = 0; k < substrings[cmp_iter].size(); k++) {
			solution.insert(substrings[cmp_iter][k]);
		}
		plagi = (((double)substrings[iter].size() + (double)substrings[cmp_iter].size() - (double)solution.size()) / ((double)substrings[0].size() + (double)substrings[1].size())) * 100;
		if(plagi > max_plagi){
			max_plagi = plagi;
			plagi_idx.first = iter;
			plagi_idx.second = cmp_iter;
		}
		cmp_iter++;
		solution.clear();
	}
}

int main() {
	int n;
	pair<int, int> plagi_idx;
	cin >> n;
	store_sentece(n);
	make_substring();
	check_plagiarism(plagi_idx);
	cout << plagi_idx.first+1 << " " << plagi_idx.second+1;
	return 0;
}
