#include <iostream>
using namespace std;
#define INT_MAX 210000000

int numarr[10] = { 0, };
int temp = 0;
int main(void) {
	for (int i = 0; i < 10; i++) cin >> numarr[i];

	for (int i = 9; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (numarr[j+1] < numarr[j]) {
				temp = numarr[j];
				numarr[j] = numarr[j + 1];
				numarr[j + 1] = temp;
			}
		}
	}

	for (auto i : numarr) cout << i << " ";

	return 0;
}
