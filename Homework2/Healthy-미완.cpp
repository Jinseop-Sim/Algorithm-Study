#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct nutri {
	int id = 0;
	int prot = 0;
	int fat = 0;
	int car = 0;
	int vit = 0;
	int pri = 0;
	int tie = 0;
	bool pick = false;
};

int n, cnt = 1, pr_s, min_sum = 2100000000;
vector<int> ans;
vector<vector<int>> an_li;
vector<nutri> foo;
nutri m_st, s_st, a_s;

bool compare(nutri& a, nutri& b) {
	return a.pri < b.pri;
}
bool compare_ans(vector<int>& a, vector<int>& b) {
	return a.back() > b.back();
}
void plus_nutri(int i) {
	s_st.prot += foo[i].prot;
	s_st.fat += foo[i].fat;
	s_st.car += foo[i].car;
	s_st.vit += foo[i].vit;
	pr_s += foo[i].pri;
	foo[i].pick = true;
}
void minus_nutri(int i) {
	s_st.prot -= foo[i].prot;
	s_st.fat -= foo[i].fat;
	s_st.car -= foo[i].car;
	s_st.vit -= foo[i].vit;
	pr_s -= foo[i].pri;
	foo[i].pick = false;
}
void backtrack(int start, vector<bool>& visit, vector<nutri>& bound) {
	if (min_sum < pr_s) return;
	if (start != n-1) {
		if (foo[start].prot + bound[start+1].prot < m_st.prot && foo[start].fat + bound[start+1].fat < m_st.fat
			&& foo[start].car + bound[start+1].car < m_st.car && foo[start].vit + bound[start+1].vit < m_st.vit) return;
	}
	if (s_st.prot >= m_st.prot && s_st.fat >= m_st.fat && s_st.car >= m_st.car && s_st.vit >= m_st.vit) {
		if (min_sum >= pr_s) {
			int n_s = 0;
			ans.clear();
			for (int i = 0; i < n; i++) if (foo[i].pick) {
				ans.push_back(foo[i].id);
				n_s += foo[i].tie;
			}
			ans.push_back(n_s);
			sort(ans.begin(), ans.end());
			if (min_sum > pr_s) { an_li.clear(); an_li.push_back(ans); }
			if (min_sum == pr_s) an_li.push_back(ans);
			min_sum = pr_s;
		}
		return;
	}
	for (int i = start; i < n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			plus_nutri(i);
			backtrack(i, visit, bound);
			visit[i] = false;
			minus_nutri(i);
		}
	}
}
int main() {
	int max_sum = 0;
	bool is_fin = false;
	nutri temp;
	cin >> n;
	cin >> m_st.prot >> m_st.fat >> m_st.car >> m_st.vit;
	vector<bool> visit(n);
	vector<nutri> bound(n);

	for (int i = 0; i < n; i++) {
		cin >> temp.prot >> temp.fat >> temp.car >> temp.vit >> temp.pri;
		temp.tie = temp.prot + temp.fat + temp.car + temp.vit; temp.id = cnt;
		a_s.prot += temp.prot; a_s.fat += temp.fat; a_s.car += temp.car; a_s.vit += temp.vit; cnt++;
		foo.push_back(temp);
	}

	bound[0] = a_s;
	for (int i = 1; i < n; i++) {
		temp.prot = bound[i-1].prot - foo[i-1].prot;
		temp.fat = bound[i-1].fat - foo[i-1].fat;
		temp.car = bound[i-1].car - foo[i-1].car;
		temp.vit = bound[i-1].vit - foo[i-1].vit;
		bound[i] = temp;
	}

	if (a_s.prot < m_st.prot || a_s.fat < m_st.fat || a_s.car < m_st.car || a_s.vit < m_st.vit) { is_fin = true; }
	if (is_fin) cout << 0;
	else {
		sort(foo.begin(), foo.end(), compare);
		backtrack(0, visit, bound);
		sort(an_li.begin(), an_li.end(), compare_ans);
		for (int i = 0; i < an_li[0].size() - 1; i++) cout << an_li[0][i] << " ";
	}
}
