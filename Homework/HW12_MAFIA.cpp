#include <algorithm>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int depth = 1;

struct info {
	string name;
	string boss;
	int parent = 0;
	pair<int, int> snd = make_pair(0, 1); // first가 부하 second가 깊이
};
void make_input(int n, vector<info> &mafia) {
	string person, boss;
	info temp;
	for (int i = 0; i < n - 1; i++) {
		cin >> person >> boss;
		temp.name = person;
		temp.boss = boss;
		mafia.push_back(temp);
	}
}
void add_boss(int n, vector<info> &mafia) {
	info temp;
	bool is_boss = true, flag = false;
	for (int i = 0; i < n - 1; i++) {
		if (is_boss == false) {
			temp.name = mafia[i - 1].boss;
			temp.parent = -1;
			mafia.push_back(temp);
			flag = true;
		}
		if (flag == true) break;
		is_boss = false;
		for (int j = 0; j < n - 1; j++) {
			if (mafia[i].boss == mafia[j].name) {
				is_boss = true;
				break;
			}
		}
	}
}
void add_parent(vector<info> &mafia) {
	for (int i = 0; i < mafia.size(); i++) {
		for (int j = 0; j < mafia.size(); j++) {
			if (mafia[i].boss == mafia[j].name) {
				mafia[i].parent = j;
				break;
			}
		}
	}
}

void dfs(vector<info> &mafia, int idx) {
	if (mafia[idx].parent == -1)
		return;
	mafia[mafia[idx].parent].snd.first++;
	depth++;
	return dfs(mafia, mafia[idx].parent);
}

void how_many_sub(vector<info> &mafia) {
	for (int i = 0; i < mafia.size(); i++) {
		depth = 1;
		dfs(mafia, i);
		mafia[i].snd.second = depth;
	}
}
bool custom_alpha(info A, info B) {
	if (A.name < B.name) return true;
	else return false;
}
bool custom_sub(info A, info B) {
	bool swap = false;
	if (A.snd.first > B.snd.first) swap = true;
	if (A.snd.first == B.snd.first && A.snd.second < B.snd.second) swap = true;
	
	return swap;
}

int main() {
	int n = 0;
	vector<info> mafia;
	cin >> n;

	make_input(n, mafia);
	add_boss(n, mafia);
	add_parent(mafia);
	how_many_sub(mafia);

	sort(mafia.begin(), mafia.end(), custom_alpha);
	stable_sort(mafia.begin(), mafia.end(), custom_sub);
	for (auto i : mafia) cout << i.name << endl;
}