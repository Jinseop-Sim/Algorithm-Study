#include <iostream>
#include <vector>
using namespace std;

struct info {
	int pos;
	int red;
	int green;
};
vector<info> info_list;
int main() {

	int num = 0, dist = 0, pos = 0, red = 0, green = 0, time = 0, prev_pos = 0;

	cin >> num >> dist;
	for (int i = 0; i < num; i++) {
		info temp;
		cin >> pos >> red >> green;
		temp.pos = pos; temp.red = red; temp.green = green;
		info_list.push_back(temp);
	}

	for (int i = 0; i < info_list.size(); i++) {
		int period = info_list[i].red + info_list[i].green;
		time += (info_list[i].pos - prev_pos);
		prev_pos = info_list[i].pos;

		if (time % period <= info_list[i].red) time += info_list[i].red - (time % period);
	}

	cout << time + (dist - prev_pos);

	return 0;
}
