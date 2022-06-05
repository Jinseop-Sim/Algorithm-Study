#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl "\n"

vector<int> pos;
vector<int> neg;
int n = 0, temp = 0, zero = 0, res = 0;

void clustering() {
	sort(pos.begin(), pos.end(), greater<int>());
	sort(neg.begin(), neg.end(), less<int>());

	if (pos.size() % 2 == 1) {
		res += pos.back();
		pos.pop_back();
	}

	if (neg.size() % 2 == 1) {
		if (zero == 0) {
			res += neg.back();
			neg.pop_back();
		}
		else neg.pop_back();
	}

	for (int i = 0; i < pos.size(); i += 2) res += pos[i] * pos[i + 1];
	for (int i = 0; i < neg.size(); i += 2) res += neg[i] * neg[i + 1];
}

int main(void) {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp < 0) neg.push_back(temp);
		if (temp > 1) pos.push_back(temp);
		if (temp == 1) res++;
		if (temp == 0) zero++;
	}

	clustering();
	cout << res;

	return 0;
}

// 수를 최대값으로 만들기 위해서는 아래의 조건들을 만족해야한다.
// 양수 : 큰 수 끼리 곱하는게 최대 이득이다.
//     마지막 남는 양수는 그냥 더한다.
// 음수 : 작은 수 끼리 곱하는게 최대 이득이다.
//     마지막 남는 음수는 0으로 상쇄할 수 있다면 상쇄하고, 아니면 그냥 더한다.
// 1은 곱하면 사라지기 때문에 그냥 더하는게 더 이득이다.
