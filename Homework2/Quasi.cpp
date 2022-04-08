#include <iostream>
#include <vector>
using namespace std;

void put_in_table(vector<vector<string>>& DP, string src, string dest, int source, int destin) {
	for (int i = source; i < source+2; i++) {
		for (int j = destin; j < destin+2; j++) {
			if (source == 0 || destin == 0) {
				if (DP[i][j].size() > 1) continue;
				else DP[i][j] = src[source];
			}
			else {
				if (DP[i][j].size() > (DP[source - 1][destin - 1] + src[source]).size()) continue;
				DP[i][j] = DP[source - 1][destin - 1] + src[source];
			}
		}
	}
}

string find_longest(vector<vector<string>> DP) {
	string ans = "";
	for (int i = 0; i < DP.size(); i++) {
		for (int j = 0; j < DP[i].size(); j++) {
			if (DP[i][j].size() > ans.size()) ans = DP[i][j];
			if (DP[i][j].size() == ans.size()) {
				if (DP[i][j] < ans) ans = DP[i][j];
			}
		}
	}

	return ans;
}

int main() {
	string src;
	string dest;

	cin >> src >> dest;
	vector<vector<string>> DP(src.size()+2, vector<string>(dest.size()+2, ""));

	for (int i = 0; i < src.size(); i++) {
		for (int j = 0; j < dest.size(); j++) {
			if (src[i] == dest[j]) put_in_table(DP, src, dest, i, j);
		}
	}

	cout << find_longest(DP);
}
