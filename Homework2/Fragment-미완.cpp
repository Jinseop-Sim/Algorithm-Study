#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

struct frag {
	int id = 0;
	string fragment;
};

int count_v[5];
int n = 0, cnt = 1, min_len = 2100000000, start = 0, end_i = 0;
frag temp_f; string temp, trash;
vector<frag> frags;
vector<frag> test;
vector<queue<frag>> frag_q(5);

int conversion(char alpha) {
	switch (alpha) {
	case 'a':
		return 0;
	case 'c':
		return 1;
	case 'g':
		return 2;
	case 'n':
		return 3;
	case 't':
		return 4;
	}
}

int main(void) {
	cin >> n;

	getline(cin, trash);
	while(1) {
		getline(cin, temp);
		if (temp == "") break;
		if (min_len > temp.length()) min_len = temp.length();
		temp_f.fragment = temp; temp_f.id = cnt; cnt++;
		frags.push_back(temp_f);
	}

	int sz = frags.size();
	while (min_len > 0) {
		for (int i = 0; i < frags.size(); i++) frag_q[conversion(frags[i].fragment[min_len-1])].push(frags[i]);
		for (int i = 0; i < 5; i++) {
			while (!frag_q[i].empty()) {
				frags.push_back(frag_q[i].front());
				frag_q[i].pop();
			}
		}
		frags.erase(frags.begin(), frags.begin() + sz);
		min_len--;
	}

	for (auto i : frags) cout << i.id << " " << i.fragment << '\n';

	return 0;
}
