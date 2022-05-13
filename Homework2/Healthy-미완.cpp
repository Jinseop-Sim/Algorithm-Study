#include <iostream>
#include <vector>
using namespace std;


struct nutri {
	int prot = 0;
	int fat = 0;
	int carbo = 0;
	int vit = 0;
	int price = 0;
	bool choose = false;
};
#define INTEGER_MAX 210000000
int n, pri_sum, min_sum = INTEGER_MAX;
vector<int> ans;
vector<nutri> food_list;
nutri min_struc, sum_struc;

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
	if (sum_struc.prot >= min_struc.prot && sum_struc.fat >= min_struc.fat && sum_struc.carbo >= min_struc.carbo && sum_struc.vit > min_struc.vit) {
		if (min_sum > pri_sum) { 
			ans.clear();
			for (int i = 0; i < n; i++) {
				if (food_list[i].choose) ans.push_back(i + 1);
			}
			min_sum = pri_sum; 
		}
		return;
	}

	for (int i = 0; i < n; i++) {
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
	nutri temp;
	cin >> n;
	cin >> min_struc.prot >> min_struc.fat >> min_struc.carbo >> min_struc.vit;

	vector<bool> visit(n);
	for (int i = 0; i < n; i++) {
		cin >> temp.prot >> temp.fat >> temp.carbo >> temp.vit >> temp.price;
		food_list.push_back(temp);
	}

	backtrack(0, visit);
	cout << endl;
	if (min_sum == INTEGER_MAX) cout << 0;
	else for (auto i : ans) cout << i << " ";
}
