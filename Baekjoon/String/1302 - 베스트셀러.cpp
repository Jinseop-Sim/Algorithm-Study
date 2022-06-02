#include <iostream>
#include <map>
using namespace std;

int n, max_n = 0;
string ans;
map<string, int, less<string>> books;
int main(void) {
	cin >> n;

	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		books[temp]++;
	}

	for (auto i : books) {
		if (i.second > max_n) {
			max_n = i.second;
			ans = i.first;
		}
	}

	cout << ans;
	return 0;
}
