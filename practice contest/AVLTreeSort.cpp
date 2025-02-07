#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

using namespace std;

template <typename T, class Comp = less<T>>
class AVLTree {
   private:
	enum class Position {
		kLEFT,
		kRIGHT,
		kROOT
	};

	struct Node {
		T e = '\0';
		Node* parent = nullptr;
		Node* left_child = nullptr;
		Node* right_child = nullptr;
		Position position;
		unsigned int height = 1;
		Node(T e, Node* parent, Position position)
			: e(e), parent(parent), position(position){};
	};

	Node* root = nullptr;

	Comp comp;

	Node* InsertSubtree(T e, Node*& node, Node* parent, Position position) {
		if (node == nullptr) {
			node = new Node(e, parent, position);
			return node;
		} else {
			if (comp(e, node->e)) {
				return InsertSubtree(e, node->left_child, node,
									 Position::kLEFT);
			} else {
				return InsertSubtree(e, node->right_child, node,
									 Position::kRIGHT);
			}
		}
	}

	unsigned int GetHeight(Node* node) {
		return (node == nullptr) ? 0 : node->height;
	}

	void RecalcHeight(Node* node) {
		if (node != nullptr)
			node->height =
				max(GetHeight(node->left_child), GetHeight(node->right_child)) + 1;
	}

	int CalcBalanceFactor(Node* node) {
		return GetHeight(node->left_child) - GetHeight(node->right_child);
	}

	void SetRelation(Node* parent, Node* child, Position position) {
		if (parent == nullptr) {
			root = child;
			child->parent = nullptr;
			child->position = Position::kROOT;
		} else if (child == nullptr) {
			if (position == Position::kLEFT) parent->left_child = nullptr;
			else if (position == Position::kRIGHT)
				parent->right_child = nullptr;
		} else {
			if (position == Position::kLEFT) parent->left_child = child;
			else if (position == Position::kRIGHT) parent->right_child = child;
			child->parent = parent;
			child->position = position;
		}
	}

	void RotateLeft(Node*& node) {
		Node* parent = node->parent;
		Node* center = node;
		Node* right_child = node->right_child;
		Node* right_left_child = node->right_child->left_child;

		SetRelation(parent, right_child, node->position);
		SetRelation(right_child, center, Position::kLEFT);
		SetRelation(center, right_left_child, Position::kRIGHT);
		node = right_child;

		RecalcHeight(node->left_child);
		RecalcHeight(node);
		RecalcHeight(node->parent);
	}

	void RotateRight(Node*& node) {
		Node* parent = node->parent;
		Node* center = node;
		Node* left_child = node->left_child;
		Node* left_right_child = node->left_child->right_child;

		SetRelation(parent, left_child, node->position);
		SetRelation(left_child, center, Position::kRIGHT);
		SetRelation(center, left_right_child, Position::kLEFT);
		node = left_child;

		RecalcHeight(node->right_child);
		RecalcHeight(node);
		RecalcHeight(node->parent);
	}

	bool Balance(Node*& node) {
		RecalcHeight(node);
		int balance_factor = CalcBalanceFactor(node);

		if (balance_factor == 0) return true;
		else if (balance_factor == 1 || balance_factor == -1) return false;
		else if (balance_factor == 2) {
			int balance_factor_l = CalcBalanceFactor(node->left_child);
			if (balance_factor_l == 1) {
				RotateRight(node);
				return false;
			} else if (balance_factor_l == 0) {
				RotateRight(node);
				return true;
			} else if (balance_factor_l == -1) {
				RotateLeft(node->left_child);
				RotateRight(node);
				return false;
			}
		} else if (balance_factor == -2) {
			int balance_factor_r = CalcBalanceFactor(node->right_child);
			if (balance_factor_r == -1) {
				RotateLeft(node);
				return false;
			} else if (balance_factor_r == 0) {
				RotateLeft(node);
				return true;
			} else if (balance_factor_r == 1) {
				RotateRight(node->right_child);
				RotateLeft(node);
				return false;
			}
		}
		exit(-1);
	}

	vector<T> Develop(Node* node) {
		if (node == nullptr) return vector<T>{};
		else {
			vector<T> v{node->e};
			vector<T> left_v = Develop(node->left_child);
			vector<T> right_v = Develop(node->right_child);

			v.insert(v.begin(), left_v.begin(), left_v.end());
			v.insert(v.end(), right_v.begin(), right_v.end());

			return v;
		}
	}

   public:
	void Insert(T e) {
		Node* inserted_node = InsertSubtree(e, root, nullptr, Position::kROOT);

		for (Node* node = inserted_node->parent; node != nullptr; node = node->parent) {
			if (bool balanced = Balance(node); balanced == true) break;
		}
	}

	vector<T> Sort() {
		return Develop(root);
	}
};

struct Compare {
	bool operator()(int n1, int n2) {
		return n1 > n2;
	}
};

int main() {
	int size;
	cout << "size : " << flush;
	cin >> size;

	vector<int> v(size);
	iota(v.begin(), v.end(), 0);
	random_device seed_gen;
	mt19937 engine(seed_gen());
	shuffle(v.begin(), v.end(), engine);

	vector<int> v1(v);
	sort(v1.begin(), v1.end());

	AVLTree<int> avl_tree;
	for (auto e : v) avl_tree.Insert(e);
	vector<int> v2 = avl_tree.Sort();

	cout << "result: " << ((v1 == v2) ? "equal" : "not equal") << endl;

	return 0;
}
