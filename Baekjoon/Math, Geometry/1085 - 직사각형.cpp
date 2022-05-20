#include <iostream>
using namespace std;

int x = 0, y = 0, w = 0, h = 0;
int mx = 0, my = 0;
int main(void) {
	cin >> x >> y >> w >> h;
	mx = min(x, y);
	my = min(w - x, h - y);
	cout << min(mx, my);
	return 0;
}
