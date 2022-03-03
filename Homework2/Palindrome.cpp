#include <iostream>
#include <string>
using namespace std;

bool is_palin = true;
bool is_quasi = false;
void palindrome_test(string palin) {
	for (int j = 0; j < palin.size()/2; j++) {
		if (palin[j] != palin[palin.size() - j - 1]) { is_palin = false;  break; }
	}
	if(is_palin) cout << 1 << endl;
}

void quasi_test(string palin) {
	string temp = palin;
	for (int i = 0; i < palin.size(); i++) {
		is_palin = true;
		palin.erase(i, 1);
		for (int j = 0; j < palin.size() / 2; j++) {
			if (palin[j] != palin[palin.size() - j - 1]) { is_palin = false;  break; }
		}
		palin = temp;
		if (is_palin) {
			cout << 2 << endl;
			return;
		}
	}
	cout << 3 << endl;
}

int main() {
	int num;
	string palin;

	cin >> num;
	for (int i = 0; i < num; i++) {
		is_palin = true;
		cin >> palin;
		palindrome_test(palin);
		if (!is_palin)	quasi_test(palin);
	}

	return 0;
}
