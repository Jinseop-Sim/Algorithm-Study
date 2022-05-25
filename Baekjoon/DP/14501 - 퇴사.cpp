#include <iostream>
#include <vector>
using namespace std;

struct sched {
	int date;
	int price;
};

int n = 0, temp_t = 0, temp_p = 0;
sched temp;
vector<sched> schedule;

void scheduling(vector<int>& DP) {
	for (int i = n - 1; i >= 0; i--) {
		int dead = i + schedule[i].date;
		if (dead > n) DP[i] = DP[i + 1];
		else DP[i] = max(DP[i + 1], DP[dead] + schedule[i].price);
	}
}

int main(void) {
	cin >> n;
	vector<int> DP(n+1, 0);
	for (int i = 0; i < n; i++) {
		cin >> temp_t >> temp_p;
		temp.date = temp_t; temp.price = temp_p;
		schedule.push_back(temp);
	}

	scheduling(DP);

	cout << DP[0];
	return 0;
}

// 이 DP문제는 특이하게 뒤에서 부터 검사했을 때, 더 쉽다.
// 뒤에서 부터 마감기한을 검사하며 마감기한이 퇴사일을 넘는 경우엔, 그냥 자기 뒷 칸 이익을 가져온다.
// 마감기한이 퇴사일 안에 들어오는 경우엔, 마감기한에 있는 이익을 현재 자기 이익에 더한 값과 이전 값 중 큰 값을 데려온다.
