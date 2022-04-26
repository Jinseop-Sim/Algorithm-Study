#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#define ll long long

vector<char> list;
int main() {
	string n;
	ll sum = 0;
	cin >> n;
	sort(n.begin(), n.end(), greater<>());

	if (n[n.size() - 1] != '0') cout << -1;
	else {
		for (auto i : n) sum += i - '0';
		if (sum % 3 == 0) cout << n;
		else cout << -1;
	}
}

// 3의 배수는 항상 모든 자리수의 합이 3으로 나누어 떨어져야만 한다!
// why? 3(n-1) + 3 = 3의 배수.
