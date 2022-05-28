#include <iostream>
using namespace std;
#define INT_MAX 210000000

int numarr[10] = { 0, };
int temp = 0, min_idx = 0;
int main(void) {
	for (int i = 0; i < 10; i++) cin >> numarr[i];

	for (int i = 0; i < 10; i++) { // 앞에서부터 차례대로 선택
		int min_v = INT_MAX;
		for (int j = i; j < 10; j++) { // 현재 선택된 값 이후로 최소 값 찾기
			if (min_v > numarr[j]) {
				min_v = numarr[j];
				min_idx = j;
			}
		}
		temp = numarr[i]; // 최소 값과 현재 선택된 index를 swap.
		numarr[i] = min_v;
		numarr[min_idx] = temp;
	}

	for (auto i : numarr) cout << i << " ";

	return 0;
}
