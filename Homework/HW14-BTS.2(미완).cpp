#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;


vector<pair<string, int>> BST(300,{"0", 0});
bool root = true;
int crit = 1;
int token(string command) {
	vector<string> op = { "+", "-", "depth", "leaf", "quit" };
	for (int i=0; i<op.size(); i++)
		if (command == op[i]) return i + 1;
}
void find_left(int idx, vector<string>& min_max) {
	if (min_max[0]<BST[idx].first) min_max[0]=BST[idx].first;
	if (BST[idx].second == 1) return;
	if(BST[idx*2].first != "0") find_left(idx*2, min_max);
	if(BST[idx*2+1].first != "0") find_left(idx * 2 + 1, min_max);
}
void find_right(int idx, vector<string>& min_max) {
	if (min_max[1]>BST[idx].first)
		if(BST[idx].first!="0") min_max[1]=BST[idx].first;
	if (BST[idx].second == 1) return;
	if (BST[idx * 2].first != "0") find_right(idx * 2, min_max);
	if (BST[idx * 2 + 1].first != "0") find_right(idx * 2 + 1, min_max);
}
string find_min(int start) {
	vector<string> min_max = {"aaa","zzz"};
	if (BST[start*2].first != "0") {
		if(BST[start*2].second == 1){
			min_max[0] = BST[start*2].first;
			return min_max[0];
		}
		find_left(start*2, min_max);
		return min_max[0];
	}
	else {
		if (BST[start*2+1].second == 1) {
			min_max[1] = BST[start*2+1].first;
			return min_max[1];
		}
		find_right(start*2+1, min_max);
		return min_max[1];
	}
}
void cmp_name(int sub, string node_name) {
	if (BST[sub].first == "0") {
		BST[sub].second = 1; BST[sub/2].second = 0;
		crit=sub;
		return;
	} 
	if (BST[sub].first >= node_name) cmp_name(sub*2, node_name);
	else cmp_name(sub*2+1, node_name);
}
void push_node(string node_name) {
	for (int i = 0; i < BST.size(); i++)
		if (BST[i].first == node_name) return;
	if (root == true) {
		BST[1].first = node_name;
		BST[1].second = 1;
		root = false;
	}
	else {
		crit = 1;
		cmp_name(1, node_name);
		BST[crit].first = node_name;
	}
}
void inner_node_change(int idx) {
	int c_idx = 0;
	if (BST[idx].second == 1) {
		if(idx%2 == 0) {if(BST[idx+1].first == "0") BST[idx/2].second = 1;}
		else {if (BST[idx-1].first == "0") BST[idx / 2].second = 1;}
		return;
	}
	string min_str = find_min(idx);
	for (int i = 0; i < BST.size(); i++) {
		if (BST[i].first == min_str) {
			c_idx = i;
			break;
		}
	}
	swap(BST[idx].first, BST[c_idx].first);
	BST[idx].second = 0;
	inner_node_change(c_idx);
}
void pop_node(string node_name) {
	int idx = 0, c_idx = 0;
	for (int i = 0; i < BST.size(); i++) {
		if (BST[i].first == node_name) {
			idx = i;
			break;
		}
	}
	if (idx == 0) return;
	if (BST[idx].second == 1) {
		BST[idx].first = "0";
		return;
	}
	BST[idx].first = "0";
	string min_str = find_min(idx);
	for (int i = 0; i < BST.size(); i++) {
		if (BST[i].first == min_str) {
			c_idx = i;
			break;
		}
	}
	swap(BST[idx].first, BST[c_idx].first);
	inner_node_change(c_idx);
}
void show_depth(int k) {
	for (int i = pow(2,k) - pow(2,k-1); i < pow(2,k); i++) {
		if (BST[i].first != "0") cout << BST[i].first << " ";
	}
	cout << endl;
}
void show_leaf() {
	for (int i = 1; i < BST.size(); i++) {
		if (BST[i].second == 1)
			if (BST[i].first != "0") cout << BST[i].first << " ";
	}
	cout << endl;
}
int main() {
	int k = 0;
	bool stop = false;
	string command, node_name;
	while (true) {
		if (stop == true) break;
		cin >> command;
		switch (token(command)) {
		case 1:
			cin >> node_name;
			push_node(node_name); break;
		case 2:
			cin >> node_name;
			pop_node(node_name); break;
		case 3:
			cin >> k;
			show_depth(k); break;
		case 4:
			show_leaf(); break;
		case 5:
			stop = true; break;
		}
	}
	for (auto k : BST) cout << k.first << " " << k.second << endl;
	return 0;
}
