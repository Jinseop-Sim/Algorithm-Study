#include <iostream>
#include <vector>
using namespace std;

int n = 0, temp = 0;
vector<int> stairs;
int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		stairs.push_back(temp);
	}
	vector<int> DP(n, 0);

	DP[0] = stairs[0]; DP[1] = DP[0] + stairs[1]; DP[2] = max(stairs[0] + stairs[2], stairs[1] + stairs[2]); // 1, 2, 3번째 계단 값은 미리 저장해놓는다.
	for (int i = 3; i < n; i++) {
		DP[i] = max(DP[i - 2] + stairs[i], DP[i - 3] + stairs[i - 1] + stairs[i]); // 여기부터는 점화식으로 표현이 가능하다.
    // 현재 계단에서 (i-2번째 계단까지의 최대) + 현재 계단 or (i-3번째 계단까지의 최대) + (i-1번째 계단) + 현재 계단.
    // 두 가지 경우 밖에 존재하지 않는다. 둘 중에 더 큰 값을 저장하며 올라가면 된다.
    // 마지막 칸은 무조건 밟으라고 했는데, 지금 저장 방식이 모든 칸을 밟았을 때의 그 위치에서 최대값이므로, 마지막 계단 Index의 값만 출력해주면 되는 것이다.
	}

	cout << DP[n-1];
	return 0;
}
