#include <iostream>
#include <fstream>
using namespace std;
struct Node
{
	int key{};
	Node* left = nullptr;
	Node* right = nullptr;
};
static void printbinarytree(Node* root, ofstream& ofst)
{
	if (root != nullptr)
	{
		ofst << root->key << endl;
		cout << root->key << endl;
		printbinarytree(root->left, ofst);
		printbinarytree(root->right, ofst);
	}
}
int main()
{
	ifstream ifst("input.txt");
	ofstream ofst("output.txt");
	Node* root = new Node;
	ifst >> root->key;
	int key{};
	while (ifst >> key)
	{
		Node* NewElement = root, * copy = new Node;
		copy->key = key;
		while ((NewElement->left != nullptr && key < NewElement->key) || (NewElement->right != nullptr && key > NewElement->key))
		{
			if (key < NewElement->key)
			{
				NewElement = NewElement->left;

			}
			else if (key > NewElement->key)
			{
				NewElement = NewElement->right;
			}
		}
		if (key < NewElement->key)
		{
			NewElement->left = copy;
		}
		else if (key > NewElement->key)
		{
			NewElement->right = copy;
		}
	}
	printbinarytree(root, ofst);
}