#include <iostream>
using namespace std;
#define INT_MAX 210000000

int numarr[10] = { 0, };
int temp = 0;
int main(void) {
	for (int i = 0; i < 10; i++) cin >> numarr[i];

	int out = 0, in = 0, key = 0;

	for (out = 1; out < 10; out++) {
		key = numarr[out];
		for (in = out - 1; in >= 0 && numarr[in]>key; in--) {
			numarr[in+1] = numarr[in];
		}
		numarr[in + 1] = key;
	}

	for (auto i : numarr) cout << i << " ";

	return 0;
}
