#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

map<set<int>, set<int, greater<int>>> code_map;
int tokenize(char command) {
	vector<char> list = { 'R', 'Q' };
	for (int i = 0; i < list.size(); i++)
		if (command == list[i]) return i;
}
void report() {
	int code = 0;
	set<int> temp;
	while (true) {
		cin >> code;
		if (code < 0) break;
		temp.insert(code);
	}
	code_map[temp].insert(code);
}
void query() {
	int code = 0;
	set<int> find_key;
	while (true) {
		cin >> code;
		if (code == 0) break;
		find_key.insert(code);
	}
	if (code_map.find(find_key) == code_map.end()) cout << "NONE";
	else for(auto ans : code_map.find(find_key)->second) cout << ans << " ";
	cout << endl;
}
int main() {
	char command = '0';
	while (true) {
		cin >> command;
		if (command == '$') break;
		switch (tokenize(command)) {
			case 0:
				report();
				break;
			case 1:
				query();
				break;
		}
	}
}
