#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

vector<string> BST(100000,"0");
bool root = true;
int crit = 1;
int token(string command) {
	vector<string> op = { "+", "-", "depth", "leaf", "quit" };
	for (int i=0; i<op.size(); i++)
		if (command == op[i]) return i + 1;
}
void find_left(int idx, vector<string>& min_max) {
	if (min_max[0]<BST[idx]) min_max[0] = BST[idx];
	if (BST[idx*2]=="0"&&BST[idx*2+1]=="0") return;
	find_left(idx*2, min_max);
	find_left(idx*2 + 1, min_max);
}
void find_right(int idx, vector<string>& min_max) {
	if (min_max[1]>BST[idx])
		if(BST[idx]!="0") min_max[1]=BST[idx];
	if (BST[idx*2]=="0"&&BST[idx*2+1] == "0") return;
	find_right(idx*2, min_max);
	find_right(idx*2+1, min_max);
}
string find_min(int start) {
	vector<string> min_max = {"aaa","zzz"};
	if (BST[start*2] != "0") {
		find_left(start*2, min_max);
		return min_max[0];
	}
	else {
		find_right(start*2+1, min_max);
		return min_max[1];
	}
}
void cmp_name(int sub, string node_name) {
	if (BST[sub] == "0") {
		crit=sub;
		return;
	}
	if (BST[sub] >= node_name) cmp_name(sub*2, node_name);
	else cmp_name(sub*2+1, node_name);
}
void push_node(string node_name) {
	for (int i = 0; i < BST.size(); i++)
		if (BST[i] == node_name) return;
	if (root == true) {
		BST[1] = node_name;
		root = false;
	}
	else {
		crit = 1;
		cmp_name(1, node_name);
		BST[crit] = node_name;
	}
}
void inner_node_change(int idx) {
	int c_idx = 0;
	string min_str = find_min(idx);
	for (int i = 0; i < BST.size(); i++) {
		if (BST[i] == min_str) {
			c_idx = i;
			break;
		}
	}
	swap(BST[idx], BST[c_idx]);
	if (BST[idx*2] == "0" && BST[idx*2+1] == "0") return;
	inner_node_change(c_idx);
}
void pop_node(string node_name) {
	int idx = 0, c_idx = 0;
	for (int i = 0; i < BST.size(); i++) {
		if (BST[i] == node_name) {
			idx = i;
		}
	}
	if (idx == 0) return;
	BST[idx] = "0";
	string min_str = find_min(idx);
	for (int i = 0; i < BST.size(); i++) {
		if (BST[i] == min_str) {
			c_idx = i;
			break;
		}
	}
	swap(BST[idx], BST[c_idx]);
	inner_node_change(c_idx);
}
void show_depth(int k) {
	for (int i = pow(2,k) - pow(2,k-1); i < pow(2,k); i++) {
		if (BST[i] != "0") cout << BST[i] << " ";
	}
	cout << endl;
}
void show_leaf() {
	for (int i = 1; i < BST.size(); i++) {
		if (i * 2 >= BST.size()) {
			break;
		}
		if (BST[i*2] == "0" && BST[i*2+1] == "0")
			if (BST[i] != "0") cout << BST[i] << " ";
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
	return 0;
}
