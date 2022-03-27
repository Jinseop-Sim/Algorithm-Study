#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct info {
	int name;
	int gold;
	int silver;
	int bronze;
};

bool cmp(info a, info b) {
	if (a.gold > b.gold) return true;
	else if (a.gold == b.gold) {
		if (a.silver > b.silver) return true;
		if (a.silver == b.silver) {
			if (a.bronze > b.bronze) return true;
		}
	}
	return false;
}

vector<info> countries;
void get_input(int n) {
	for (int i = 0; i < n; i++) {
		info temp;
		int c, g, s, b;
		cin >> c >> g >> s >> b;
		temp.name = c; temp.gold = g; temp.silver = s; temp.bronze = b;
		countries.push_back(temp);
	}
}

int make_rank(int n, int k) {
	sort(countries.begin(), countries.end(), cmp);

	int target_idx = 0, equal = 0;
	for (int i = 0; i < n; i++) {
		if (countries[i].name == k) { target_idx = i; break; }
	}

	for (int i = target_idx - 1;; i--) {
		if (countries[i].gold != countries[target_idx].gold || countries[i].silver != countries[target_idx].silver
			|| countries[i].bronze != countries[target_idx].bronze) break;
		equal++;
	}

	return target_idx - equal + 1;
}

int main() {
	int n, k;
	cin >> n >> k;
	
	get_input(n);
	cout << make_rank(n, k);

	return 0;
}
