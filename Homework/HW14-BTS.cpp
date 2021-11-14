#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

vector <string> BST(50, "0");
bool root = true;
int crit = 1;
int token(string command) {
	vector<string> op = { "+", "-", "depth", "leaf", "quit" };
	for (int i = 0; i < op.size(); i++)
		if (command == op[i]) return i + 1;
}
string find_min(int start) {
	string min_str = "zzz";
	string max_str = "aaa";
	if (BST[start * 2] != "0") {
		for (int i = start*2; i < BST.size(); i = i * 2) {
			if (BST[i] != "0") {
				if (min_str > BST[i]) min_str = BST[i];
			}
			if (BST[i * 2] == "0" && BST[i * 2 + 1] == "0") break;
		}
		return min_str;
	}
	else {
		for (int i = start; i < BST.size(); i = (i * 2) + 1) {
			if (BST[i] != "0") {
				if (max_str < BST[i]) max_str = BST[i];
			}
			if (BST[i * 2] == "0" && BST[i * 2 + 1] == "0") break;
		}
		return max_str;
	}
}
void cmp_name(int sub, string node_name) {
	if (BST[sub] == "0") {
		crit = sub;
		return;
	}
	if (BST[sub] >= node_name) cmp_name(sub * 2, node_name);
	else cmp_name(sub * 2 + 1, node_name);

}
void push_node(string node_name) {
	int sub = 1;
	bool exist = false;
	for (int i = 0; i < BST.size(); i++)
		if (BST[i] == node_name) return;
	if (root == true) {
		BST[1] = node_name;
		root = false;
	}
	else {
		crit = 1;
		cmp_name(sub, node_name);
		BST[crit] = node_name;
		cout << crit << endl;
	}
}
void pop_node(string node_name) {
	int idx = 0, min_idx = 0, max_idx = 0;
	for (int i = 0; i < BST.size(); i++){
		if (BST[i] == node_name) {
			idx = i;
		}
	}
	BST[idx] = "0";
	string min_str = find_min(idx);
	cout << min_str << endl;
	for (int i = 0; i < BST.size(); i++) {
		if (BST[i] == min_str) {
			min_idx = i;
			break;
		}
	}
	cout << BST[idx] << " " << BST[min_idx] << endl;
	swap(BST[idx], BST[min_idx]);
}
void show_depth(int k) {
	for (int i = pow(2, k) - pow(2, k - 1); i < pow(2, k); i++) {
		if (BST[i] != "0") cout << BST[i] << " ";
	}
	cout << endl;
}
void show_leaf() {
	for (int i = 1; i < BST.size(); i++) {
		if (i * 2 >= BST.size()) {
			break;
		}
		if (BST[i * 2] == "0" && BST[i * 2 + 1] == "0")
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
	for (auto i : BST) cout << i << " ";
	return 0;
}
