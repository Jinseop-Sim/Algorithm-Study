#include <iostream>
#include <vector>
using namespace std;

int item = 0, limit = 0;
vector<pair<int, int>> item_list;
int main() {
	int weight = 0, price = 0;
	cin >> item >> limit;
	vector<vector<int>> DP(item+1, (vector<int>(limit+1, 0))); // 열 번호는 무게를 뜻하고, 행 번호는 각 item의 번호가 된다.

	for (int i = 0; i < item; i++) {
		cin >> weight >> price;
		item_list.push_back(make_pair(weight, price));
	}

	for (int i = 1; i < item+1; i++) {
		for (int j = 1; j < limit+1; j++) {
			if (j - item_list[i-1].first >= 0) DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - item_list[i-1].first] + item_list[i-1].second);
        // 현재 item을 넣었을 때 무게가 남는다면?
        // 이전에 하나만 넣었던 Item을 그대로 넣어 놓느냐, 아니면
	// (현재 무게 한도 - 현재 Item 무게)를 한 칸의 값을 더한 값을 저장하느냐.
        // 둘 중 무거운 것으로 넣는다.
			else DP[i][j] = DP[i - 1][j];
        // 무게가 남지 않는 경우에는 이전에 하나만 넣었던 Item을 그대로 계속 가져온다.
		}
	}

	cout << DP[item][limit];

	return 0;
}
