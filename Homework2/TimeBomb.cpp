#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include "timebomb.h"
using namespace std;

vector<int> large_idx;
vector<pair<int, int>> tornament;

void find_max() {
	while (large_idx.size() != 1) {
		vector<int> temp;
		for (int i = 0; i < large_idx.size(); i++) {
			if (i == large_idx.size() - 1) { temp.push_back(large_idx[i]); break; }
			tornament.push_back(make_pair(large_idx[i], large_idx[i + 1]));
			if (box_comp(large_idx[i], large_idx[i + 1]) == -1) temp.push_back(large_idx[i + 1]);
			else temp.push_back(large_idx[i]);
			i++;
		}
		large_idx.clear();
		large_idx = temp;
	}
}

void make_tournament(int max_idx) {
	for (int i = 0; i < tornament.size(); i++) {
		if (tornament[i].first == max_idx) large_idx.push_back(tornament[i].second);
		else if (tornament[i].second == max_idx) large_idx.push_back(tornament[i].first);
	}
}

int main() {
	int N = 0, result = 0, dis = 0, max_idx = 0;

	box_ready();
	N = box_size();

	for (int i = 1; i < N+1; i++) {
		if (i == N) { large_idx.push_back(i); break; }
		tornament.push_back(make_pair(i, i + 1));
		if (box_comp(i, i + 1) == -1) large_idx.push_back(i + 1);
		else large_idx.push_back(i);
		i++;
	}

	find_max();
	max_idx = large_idx[0];
	large_idx.clear();

	make_tournament(max_idx);
	find_max();
	dis = large_idx[0];
	box_report(dis);

	return 0;
}

// 아이디어가 굉장히 중요한 문제였다.
// 먼저 가장 무거운 것을 찾은 후, 가장 무거운 것과 대결했던 폭탄들끼리 다시 싸우게 한다.
// 그 중 가장 무거운 것이 두 번째로 무거운 것!
