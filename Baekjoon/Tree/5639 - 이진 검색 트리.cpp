#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
};

Node* make_bst(Node* node, int data) {
	if (node == NULL) {
		node = new Node();
		node->data = data;
		node->left = node->right = NULL;
	}
	else if (data <= node->data)
		node->left = make_bst(node->left, data);
	else
		node->right = make_bst(node->right, data);
	return node;
}

void postorder(Node* node) {
	if (node->left != NULL)
		postorder(node->left);
	if (node->right != NULL)
		postorder(node->right);
	cout << node->data << '\n';
}

int main() {
	Node* root = NULL;
	int num = 0;

	while (cin >> num) {
		if (num == EOF) break;
		root = make_bst(root, num);
	}
	
	postorder(root);
	return 0;
}
