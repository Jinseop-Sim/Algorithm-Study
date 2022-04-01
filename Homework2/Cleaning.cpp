#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct info {
	int start;
	int end;
	int pay;
	int days;
};
vector<info> task_list;

bool cmp(info a, info b) {
	return a.start < b.start;
}

int make_task(int n) {
	int start = 0, end = 0, pay = 0, last_day = 0;
	for (int i = 0; i < n; i++) {
		info temp;
		cin >> start >> end >> pay;
		if (last_day < end) last_day = end;
		temp.start = start; temp.end = end; temp.pay = pay-10; temp.days = end - start + 1;
		task_list.push_back(temp);
	}
	sort(task_list.begin(), task_list.end(), cmp);

	return last_day;
}

int custom_max(int a, int b, int i, vector<int>& DAY, vector<int> DP) {
	int min_day = 0;
	if (a > b) {
		DAY[task_list[i].start] = DAY[task_list[i+1].start];
		return a;
	}
	else {
		if (i == task_list.size() - 1) DAY[task_list[i].start] = task_list[i].days;
		else {
			if (b == DP[task_list[i+1].start]) {
				min_day = min(DAY[task_list[i+1].start], DAY[task_list[i].end + 1] + task_list[i].days);
				DAY[task_list[i].start] = min_day;
			}
			else DAY[task_list[i].start] = DAY[task_list[i].end + 1] + task_list[i].days;
		}
		return b;
	}
}

void dy_pro(vector<int>& DP, vector<int>& DAY) {
	for (int i = task_list.size() - 1; i >= 0; i--) {
		int temp = 0;
		if (i == task_list.size() - 1) DP[task_list[i].start] = custom_max(DP[task_list[i].start + 1], DP[task_list[i].end + 1] + task_list[i].pay, i, DAY, DP);
		else {
			if (task_list[i].start == task_list[i + 1].start) {
				temp = custom_max(DP[task_list[i].start + 1], DP[task_list[i].end + 1] + task_list[i].pay, i, DAY, DP);
				if (temp > DP[task_list[i].start]) DP[task_list[i].start] = temp;
			}
			else DP[task_list[i].start] = custom_max(DP[task_list[i].start + 1], DP[task_list[i].end + 1] + task_list[i].pay, i, DAY, DP);
		}
		if (i != 0) {
			for (int k = task_list[i - 1].start + 1; k < task_list[i].start; k++) {
				DP[k] = DP[task_list[i].start];
				DAY[k] = DAY[task_list[i].start];
			}
		}
	}
}

int main() {
	int n = 0, idx = 2000, last_day = 0;
	int res1, res2;
	cin >> n;

	last_day = make_task(n);
	vector<int> DP(last_day+2);
	vector<int> DAY(last_day+2);
	dy_pro(DP, DAY);

	res1 = *max_element(DP.begin(), DP.end());
	res2 = *max_element(DAY.begin(), DAY.end());
	cout << res1+10 << " " << res2;
	return 0;
}
