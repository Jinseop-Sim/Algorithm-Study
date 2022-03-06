#include <iostream>
#include <string>
using namespace std;

void backspace(string s, string t) {
	bool wrong = true;

	for (int i = 0; i < s.size(); i++) {
		int t_idx = 0, curr_idx = 0, prev_idx = 0;
		bool is_first = true;
		for (int j = i; j < s.size(); j++) {
			if (s[j] == t[t_idx]) {
				if (is_first) {
					if (t_idx == t.size() - 1) {
						wrong = false; break;
					}
					curr_idx = j; t_idx++;
					is_first = false;
					continue;
				}
				if (!is_first) {
					prev_idx = curr_idx;
					curr_idx = j;
					if ((curr_idx - prev_idx - 1) % 2 != 0) { curr_idx = prev_idx;  continue; }
				}
				if (t_idx == t.size() - 1) {
					if (((s.size() - 1) - curr_idx) % 2 != 0) break;
					else { wrong = false; break; }
				}
				t_idx++;
			}
		}
		if (!wrong) break;
	}
	if (!wrong) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	int n = 0;
	string s, t;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> s;
		cin >> t;
		if (s.size() < t.size()) {
			cout << "NO" << endl;
			continue;
		}
		backspace(s, t);
	}
	return 0;
}
