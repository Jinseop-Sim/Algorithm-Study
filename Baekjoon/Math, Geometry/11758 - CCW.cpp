#include <iostream>
#include <vector>
using namespace std;
#define endl "\n"

struct Coord {
	int x;
	int y;
};

int n = 0, signedArea = 0;
vector<Coord> dots(4);
int main(void) {
	for (int i = 0; i < 3; i++) cin >> dots[i].x >> dots[i].y;
	dots[3] = dots[0];

	for (int i = 0; i < 3; i++) {
		signedArea += (dots[i].x * dots[i + 1].y);
		signedArea -= (dots[i].y * dots[i + 1].x);
	}

	if (signedArea < 0) cout << -1;
	if (signedArea > 0) cout << 1;
	if (signedArea == 0) cout << 0;
	return 0;
}
