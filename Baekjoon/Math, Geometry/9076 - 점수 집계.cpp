#include <iostream>
#include <algorithm>
using namespace std;

int n, score[5] = {0,};
int main(void) {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++)
			cin >> score[j];
		sort(score, score + 5);
		if (score[3] - score[1] >= 4) cout << "KIN" << '\n';
		else cout << score[1] + score[2] + score[3] << '\n';
	}
	return 0;
}
