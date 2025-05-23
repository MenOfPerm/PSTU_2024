// 18 int найти мин элем в дереве
#include <algorithm>
#include <cmath>
#include <iostream>
#include <random>
using namespace std;
struct Node {
	int data;
	Node* left;
	Node* right;
	Node(int key) {
		data = key;
		left = nullptr;
		right = nullptr;
	}
};

int create(Node* node,int m) 
{
	
	
	if (m<0)
	{
		return 0 ;
	}
	else
	{
		srand(time(NULL));
		create(node->left = new Node(rand() % 10), m - 1);
		create(node->right = new Node(rand() % 10), m - 2);
	}


}
int btHeight(Node* node)
{
	if (!node) return 0; // высота пустого дерева всегда 0
	// если у нас дерево с узлами, то узел дает высоту 1
	// + добавляем максимальную высоту каждого из его потомков
	return 1 + std::max(btHeight(node->left), btHeight(node->right));
};
bool isBTBalanced(Node* root)
{
	// пустое дерево всегда в балансе
	if (!root) return true;
	// считаем высоту левого и правого поддеревьев
	int lSubTreeHeight = btHeight(root->left);
	int rSubTreeHeight = btHeight(root->right);
	if (std::abs(lSubTreeHeight - rSubTreeHeight) > 1) return false;
	return isBTBalanced(root->left) && isBTBalanced(root->right);
};
int find_min_rec(Node* node, int min, int m)
{
	if (m <= 0 || node == nullptr)
	{
		return min;
	}
	if (node!=nullptr)
	{
		if (node->data < min)
		{
			min = node->data;
		}
	}
	
	find_min_rec(node->left, min, m-1);
	find_min_rec(node->right, min, m-1);
}
int find_min(Node* root)
{
	int lSubTreeHeight = btHeight(root->left);
	int rSubTreeHeight = btHeight(root->right);
	int min_left = find_min_rec(root->left, 999, lSubTreeHeight);
	int min_right = find_min_rec(root->right, 999, rSubTreeHeight);
	return min(min_left, min_right);

}
int main() {
	setlocale(LC_CTYPE, "RU");
	/*Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->left->left->left = new Node(6);*/
	Node* root = new Node(2);
	create(root, 5);
	cout << find_min(root)<<endl;
	//cout<<btHeight(root);
	cout << root->left->data;
	cout << root->right->data<<endl;
	//cout << (isBTBalanced(root) ? "Дерево сбалансированное":"Дерево несбалансированное") << endl;
	return 0;
}


