#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define COORD_MAX 20000000.0

struct Coord {
	double x, y, z;
};
Coord A, B, C, D;
Coord S1, S2;
void input_coord() {
	cin >> A.x >> A.y >> A.z;
	cin >> B.x >> B.y >> B.z;
	cin >> C.x >> C.y >> C.z;
	cin >> D.x >> D.y >> D.z;
}

double calc_coord() {
	double dist = 0.0, prev_min = COORD_MAX + 1, min = COORD_MAX;
	double diff = 1000;
	for (double t = 0; t < diff + 1; t++) {
		if (prev_min > min) prev_min = min;
		else break;
		S1.x = (t / diff) * B.x + (1 - (t / diff)) * A.x;
		S1.y = (t / diff) * B.y + (1 - (t / diff)) * A.y;
		S1.z = (t / diff) * B.z + (1 - (t / diff)) * A.z;
		for (double e = 0; e < diff + 1; e++) {
			S2.x = (e / diff) * D.x + (1 - (e / diff)) * C.x;
			S2.y = (e / diff) * D.y + (1 - (e / diff)) * C.y;
			S2.z = (e / diff) * D.z + (1 - (e / diff)) * C.z;

			cout << "<" << S1.x << ", " << S1.y << ", " << S1.z << "> ";
			cout << "<" << S2.x << ", " << S2.y << ", " << S2.z << ">" << endl;
			dist = sqrt(pow((S1.x - S2.x), 2) + pow((S1.y - S2.y), 2) + pow((S1.z - S2.z), 2));
			if (min > dist) min = dist;
			cout << min << endl;
		}
	}
	
	return min;
}

int main() {
	input_coord();
	cout << int(ceil(calc_coord())) << endl;
	return 0;
}
