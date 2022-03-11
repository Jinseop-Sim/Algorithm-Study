#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool is_origin(vector<int> breads) {
	for (int i = 0; i < breads.size(); i++) {
		if (breads[i] != i + 1) return false;
	}
}

bool find_reverse(vector<int>& breads) {
	int org_value = 0, org_idx = 0;
	for (int i = 0; i < breads.size(); i++) {
		if (breads[i] != i + 1) {
			org_value = i + 1;
			for (int j = i; j < breads.size(); j++) {
				if (abs(breads[j]) == org_value) { org_idx = j; break; }
			}
			reverse(breads.begin() + i, breads.begin()+org_idx+1);
			for (int j = i; j < org_idx + 1; j++) { breads[j] = breads[j] * (-1); }
			break;
		}
	}
	return is_origin(breads);
}

bool back_find_reverse(vector<int>& breads) {
	int org_value = 0, org_idx = 0;
	for (int i = breads.size()-1; i >= 0; i--) {
		if (breads[i] != i + 1) {
			org_value = i + 1;
			for (int j = i; j >= 0; j--) {
				if (abs(breads[j]) == org_value) { org_idx = j; break; }
			}
			reverse(breads.begin() + org_idx, breads.begin() + i + 1);
			for (int j = org_idx; j < i + 1; j++) { breads[j] = breads[j] * (-1); }
			break;
		}
	}
	return is_origin(breads);
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < 5; i++) {
		vector<int> breads;
		vector<int> rev_breads;
		bool is_once = true;
		int bread, cnt = 0;

		for (int j = 0; j < n; j++) {
			cin >> bread;
			breads.push_back(bread);
			rev_breads.push_back(bread);
		}

		if (find_reverse(breads)) cout << "one" << endl;
		else {
			back_find_reverse(rev_breads);
			if (find_reverse(breads) || back_find_reverse(rev_breads)) { cout << "two" << endl; }
			else cout << "over" << endl;
		}
	}
	return 0;
}
