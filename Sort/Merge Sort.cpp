#include <iostream>
using namespace std;
#define INT_MAX 210000000

int numarr[10] = { 0, };
int sorted[10] = { 0, };

void merge(int start, int end) {
	int mid = (start + end) / 2;

	int i = start;
	int j = mid + 1;
	int k = start;

	while (i <= mid && j <= end) {
		if (numarr[i] <= numarr[j]) sorted[k++] = numarr[i++]; // 잘린 두 배열의 값을 비교해서 작은 값이 먼저 Sorted 배열에 들어간다.
		else sorted[k++] = numarr[j++];
	}

	if (i > mid) while (j <= end) sorted[k++] = numarr[j++]; // 위의 과정을 거치고도 남은 값들을 Sorted 배열에 집어넣는다.
	else while (i <= mid) sorted[k++] = numarr[i++];

	for (int i = start; i <= end; i++) numarr[i] = sorted[i]; // 원래의 배열에 Sorted 배열을 복사한다.
}

void merge_sort(int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		merge_sort(start, mid); // 이 부분으로 인해서 10개의 배열이 1개짜리까지 쪼개진다.
		merge_sort(mid + 1, end);
		merge(start, end); // 여기서부터 1개짜리 비교
	}
}

int main(void) {
	for (int i = 0; i < 10; i++) cin >> numarr[i];

	merge_sort(0, 9);
	for (auto i : numarr) cout << i << " ";

	return 0;
}
