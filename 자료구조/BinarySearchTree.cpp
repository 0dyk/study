#include<iostream>

#define MAX_NODE 101

struct Node {
	int key;
	Node* left;
	Node* right;
}nodes[MAX_NODE];

Node* new_node(int x) {
	nodes[node_count].key = x;
	nodes[node_count].left = nullptr;
	nodes[node_count].right = nullptr;

	return &nodes[node_count++];
}

class BinarySearchTree {
	Node* root;

public:
	void init() {	// �ʱ�ȭ
		node_count = 0;
		root = nullptr;
	}

	void insert(int x) {	// ����
		root = insert_rec(root, x);
	}

	void remove(int x) {	// ����
		root = remove_rec(root, x);
	}

	bool find(int x) {
		Node* node = root;
		while (node != nullptr) {
			if (node->key == x) {
				std::cout << "find" << '\n';
				return true;
			}

			node = (x < node->key) ? node->left : node->right;
		}

		std::cout << "nofind" << '\n';
		return false;
	}

	void traversal(int type) {
		traversal_rec(root, type);
		std::cout << '\n';
	}

private:
	Node* insert_rec(Node* node, int x) {
		if (node == nullptr) return new_node(x);

		if (x < node->key) {
			node->left = insert_rec(node->left, x);
		}
		else if (x > node->key) {
			node->right = insert_rec(node->right, x);
		}

		return node;
	}

	Node* remove_rec(Node* node, int x) {
		if (node == nullptr) return node;

		if (x < node->key) {
			node->left = remove_rec(node->left, x);
		}
		else if (x > node->key) {
			node->right = remove_rec(node->right, x);
		}
		else {	// ã�� ���
			if (node->left == nullptr) {	// ������ �ڽĸ� �ִ� ���
				return node->right;
			}
			else if (node->right == nullptr) {	// ���� �ڽĸ� �ִ� ���
				node->left;
			}

			// ���� �ڽ� ��� ���� �ϴ� ���
			int temp = find_min_key(node->right);	// ������ �κ�Ʈ������ �ּҰ��� ã�� ��
			node->key = temp;	// ������ �ϴ� ���� ����� �߰����� �ֱ�
			node->right = remove_rec(node->right, temp);	// ������ �κ�Ʈ������ temp�� ����
		}

		return node;
	}

	int find_min_key(Node* node) {	// ���� ���� key��
		while (node->left != nullptr) {
			node = node->left;
		}
		return node->key;
	}

	void traversal_rec(Node* node, int type) { // 0 ����, 1 ����, 2 ����
		if (node == nullptr) return;

		if (type == 0) std::cout << node->key << ' ';
		traversal_rec(node->left, type);
		if (type == 1) std::cout << node->key << ' ';
		traversal_rec(node->right, type);
		if (type == 2) std::cout << node->key << ' ';
	}

};

int main() {
	BinarySearchTree bst;

	bst.init();

	bst.insert(10);
	bst.insert(7);
	bst.insert(12);
	bst.insert(5);
	bst.insert(15);
	bst.insert(9);
	bst.insert(13);
	bst.insert(6);
	bst.insert(2);
	bst.insert(3);

	bst.traversal(0);
	bst.traversal(1);
	bst.traversal(2);

	bst.find(2);

	bst.remove(1);
	bst.remove(5);
	bst.remove(7);
	bst.remove(2);

	bst.find(2);

	bst.traversal(0);

	return 0;
}