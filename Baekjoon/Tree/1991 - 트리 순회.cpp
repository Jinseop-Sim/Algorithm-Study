#include <iostream>
using namespace std;

int n = 0;
pair<int, int> node[26];

void preorder(char curr){
	if (curr == '.') return;
	
	cout << curr;
	preorder(node[curr - 'A'].first);
	preorder(node[curr - 'A'].second);
}

void inorder(char curr) {
	if (curr == '.') return;

	inorder(node[curr - 'A'].first);
	cout << curr;
	inorder(node[curr - 'A'].second);
}

void postorder(char curr) {
	if (curr == '.') return;

	postorder(node[curr - 'A'].first);
	postorder(node[curr - 'A'].second);
	cout << curr;
}

int main(void) {
	cin >> n;

	for (int i = 0; i < n; i++) {
		char parent, left, right;
		cin >> parent >> left >> right;
		node[parent - 'A'] = make_pair(left, right);
	}

	preorder('A');
	cout << '\n';
	inorder('A');
	cout << '\n';
	postorder('A');
	return 0;
}
