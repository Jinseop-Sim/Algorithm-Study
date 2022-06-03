#include <iostream>
#include <vector>
using namespace std;
#define endl "\n"

struct Coord {
	int x;
	int y;
};

int n = 0;

void make_map(vector<Coord>& maps) {
	for (int i = 1; i < n + 1; i++) cin >> maps[i].x >> maps[i].y;
	maps[0] = maps[n];
	maps[n + 1] = maps[1];
}

void can_marina(vector<Coord>& maps) {
	for (int i = 1; i < n + 1; i++) {
		int signedArea = 0;
		signedArea += (maps[i - 1].x * maps[i].y + maps[i].x * maps[i + 1].y + maps[i + 1].x * maps[i - 1].y); // Outer product
		signedArea -= (maps[i - 1].y * maps[i].x + maps[i].y * maps[i + 1].x + maps[i + 1].y * maps[i - 1].x);

		if (signedArea < 0) cout << i << endl;
	}
}

int main(void) {
	cin >> n;
	vector<Coord> maps(n + 2);

	make_map(maps);
	can_marina(maps);

	return 0;
}
