#include <iostream>
#include <vector>
using namespace std;

int main() {
	int yut = 0;
	for (int i = 0; i < 3; i++) {
		int count = 0;
		vector<int> yuts;
		for (int j = 0; j < 4; j++) {
			cin >> yut;
			yuts.push_back(yut);
		}

		for (int j = 0; j < yuts.size(); j++) {
			if (yuts[j] == 0) count += 1;
		}

		switch (count) {
		case 0: cout << "E" << endl; break;
		case 1: cout << "A" << endl; break;
		case 2: cout << "B" << endl; break;
		case 3: cout << "C" << endl; break;
		case 4: cout << "D" << endl; break;
		}
	}
	return 0;
}
