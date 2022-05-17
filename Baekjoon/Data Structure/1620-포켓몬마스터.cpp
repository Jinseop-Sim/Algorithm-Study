#include <iostream>
#include <cstdlib>
#include <map>
#include <string>
using namespace std;

map<int, string> pokemon_1;
map<string, int> pokemon_2;
string name, quest;
int n, m;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> name;
		pokemon_1[i+1] = name;
		pokemon_2[name] = i + 1;
	}

	for (int i = 0; i < m; i++) {
		cin >> quest;
		if (quest[0] < 'A') cout << pokemon_1[stoi(quest)] << '\n';
		else cout << pokemon_2[quest] << '\n';
	}

	return 0;
}
