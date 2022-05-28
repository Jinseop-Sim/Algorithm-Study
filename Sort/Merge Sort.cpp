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
		if (numarr[i] <= numarr[j]) sorted[k++] = numarr[i++];
		else sorted[k++] = numarr[j++];
	}

	if (i > mid) while (j <= end) sorted[k++] = numarr[j++];
	else while (i <= mid) sorted[k++] = numarr[i++];

	for (int i = start; i <= end; i++) numarr[i] = sorted[i];
}

void merge_sort(int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		merge_sort(start, mid);
		merge_sort(mid + 1, end);
		merge(start, end);
	}
}

int main(void) {
	for (int i = 0; i < 10; i++) cin >> numarr[i];

	merge_sort(0, 9);
	for (auto i : numarr) cout << i << " ";

	return 0;
}
