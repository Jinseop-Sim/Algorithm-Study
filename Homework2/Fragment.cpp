#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct frag {
	int id = 0;
	string fragment;
};

int n = 0, cnt = 1;
frag temp_f; string temp, trash;
vector<frag> frags;

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

void msd_radix(int sta, int end, int wh, vector<frag>& sol_v) {
	if (end <= sta + 1) return;

	int count_v[6] = { 0, };
	int temp_count[6] = { 0, };

	for (int i = sta; i < end; i++) { 
		count_v[conversion(frags[i].fragment[wh]) + 1]++;
		temp_count[conversion(frags[i].fragment[wh]) + 1]++;
	}
	for (int i = 0; i < 5; i++) { 
		count_v[i + 1] += count_v[i]; 
		temp_count[i + 1] += temp_count[i]; 
	}
	for (int i = sta; i < end; i++) sol_v[sta + temp_count[conversion(frags[i].fragment[wh])]++] = frags[i];
	for (int i = sta; i < end; i++) frags[i] = sol_v[i];

	for (int i = 0; i < 5; i++) msd_radix(sta + count_v[i], sta + count_v[i + 1], wh + 1, sol_v);
}

int main(void) {
	cin >> n;

	getline(cin, trash);
	while (1) {
		getline(cin, temp);
		if (temp == "") break;
		temp_f.fragment = temp; temp_f.id = cnt; cnt++;
		frags.push_back(temp_f);
	}

	vector<frag> sol_v(frags.size());
	msd_radix(0, frags.size(), 0, sol_v);

	cout << frags[n - 2].id << '\n';
	cout << frags[n - 1].id << '\n';
	cout << frags[n].id << '\n';

	return 0;
}
