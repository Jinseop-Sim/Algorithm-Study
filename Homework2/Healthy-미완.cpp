#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct nutri {
	int id = 0;
	int prot = 0;
	int fat = 0;
	int carbo = 0;
	int vit = 0;
	int price = 0;
	int tie = 0;
	bool choose = false;
};

#define INTEGER_MAX 210000000
int n, cnt = 1, pri_sum, min_sum = INTEGER_MAX;
vector<int> ans;
vector<vector<int>> ans_list;
vector<nutri> food_list;
nutri min_struc, sum_struc, all_sum;

bool compare(nutri& a, nutri& b) {
	return a.price < b.price;
}

bool compare_ans(vector<int>& a, vector<int>& b) {
	return a[a.size() - 1] > b[b.size() - 1];
}

void plus_nutri(int i) {
	sum_struc.prot += food_list[i].prot;
	sum_struc.fat += food_list[i].fat;
	sum_struc.carbo += food_list[i].carbo;
	sum_struc.vit += food_list[i].vit;
	pri_sum += food_list[i].price;
	food_list[i].choose = true;
}

void minus_nutri(int i) {
	sum_struc.prot -= food_list[i].prot;
	sum_struc.fat -= food_list[i].fat;
	sum_struc.carbo -= food_list[i].carbo;
	sum_struc.vit -= food_list[i].vit;
	pri_sum -= food_list[i].price;
	food_list[i].choose = false;
}

void backtrack(int start, vector<bool>& visit) {
	if (min_sum < pri_sum) return;
	if (sum_struc.prot >= min_struc.prot && sum_struc.fat >= min_struc.fat && sum_struc.carbo >= min_struc.carbo && sum_struc.vit >= min_struc.vit) {
		if (min_sum >= pri_sum) {
			int nut_sum = 0;
			ans.clear();
			for (int i = 0; i < n; i++) if (food_list[i].choose) {
				ans.push_back(food_list[i].id);
				nut_sum += food_list[i].tie;
			}
			ans.push_back(nut_sum);
			sort(ans.begin(), ans.end());
			if (min_sum > pri_sum) { ans_list.clear(); ans_list.push_back(ans); }
			if (min_sum == pri_sum) ans_list.push_back(ans);
			min_sum = pri_sum;
		}
		return;
	}

	for (int i = start; i < n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			plus_nutri(i);
			backtrack(i, visit);
			visit[i] = false;
			minus_nutri(i);
		}
	}
}

int main() {
	int max_sum = 0;
	nutri temp;
	cin >> n;
	cin >> min_struc.prot >> min_struc.fat >> min_struc.carbo >> min_struc.vit;

	vector<bool> visit(n);
	for (int i = 0; i < n; i++) {
		cin >> temp.prot >> temp.fat >> temp.carbo >> temp.vit >> temp.price; 
		temp.tie = temp.prot + temp.fat + temp.carbo + temp.vit; temp.id = cnt;
		all_sum.prot += temp.prot; all_sum.fat += temp.fat; all_sum.carbo += temp.carbo; all_sum.vit += temp.vit; cnt++;
		food_list.push_back(temp);
	}

	sort(food_list.begin(), food_list.end(), compare);

	if (all_sum.prot < min_struc.prot || all_sum.fat < min_struc.fat || all_sum.carbo < min_struc.carbo || all_sum.vit < min_struc.vit) {}
	else backtrack(0, visit);

	sort(ans_list.begin(), ans_list.end(), compare_ans);

	if (min_sum == INTEGER_MAX) cout << 0;
	else for (int i = 0; i < ans_list[0].size() - 1; i++) cout << ans_list[0][i] << " ";
}
