#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

#define ll long long

vector<ll> nums;
vector<char> oper;

ll calc(ll a, ll b, char op)
{
	switch (op)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	}
}

void init(vector<vector<ll>>& DP, vector<vector<ll>>& min_DP) {
	for (int i = 0; i < nums.size(); i++)
	{
		DP[i][i] = min_DP[i][i] = nums[i];
	}
}

void fill_DP(vector<vector<ll>>& DP, vector<vector<ll>>& min_DP) {
	for (int cnt = 1; cnt < nums.size(); cnt++)
	{
		for (int idx = 0; idx < nums.size() - cnt; idx++)
		{
			for (int i = 1, j = cnt; i <= cnt; i++, j--)
			{
				int oper_idx = idx + cnt - j;
				char op = oper[oper_idx];

				ll cmp_list[4] = {
					calc(DP[idx][idx + cnt - j], DP[idx + i][idx + cnt], op),
					calc(DP[idx][idx + cnt - j], min_DP[idx + i][idx + cnt], op),
					calc(min_DP[idx][idx + cnt - j], DP[idx + i][idx + cnt], op),
					calc(min_DP[idx][idx + cnt - j], min_DP[idx + i][idx + cnt], op)
				};

				sort(cmp_list, cmp_list + 4);

				DP[idx][idx + cnt] = max(DP[idx][idx + cnt], cmp_list[3]);
				min_DP[idx][idx + cnt] = min(min_DP[idx][idx + cnt], cmp_list[0]);
			}
		}
	}
}

int main(void)
{
	int cnt = 0; ll temp_n = 0;
	char temp_op;

	do {
		if (cnt % 2 == 0) { 
			cin >> temp_n; 
			nums.push_back(temp_n);
		}
		else {
			cin >> temp_op;
			oper.push_back(temp_op);
		}
		cnt++;
	} while (getc(stdin) == ' ');

	vector<vector<ll>> DP(nums.size(), vector<ll>(nums.size(), LLONG_MIN));
	vector<vector<ll>> min_DP(nums.size(), vector<ll>(nums.size(), LLONG_MAX));

	init(DP, min_DP);
	fill_DP(DP, min_DP);

	cout << DP[0][nums.size() - 1];

	return 0;
}
