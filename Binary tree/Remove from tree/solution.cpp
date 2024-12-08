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
		printbinarytree(root->left, ofst);
		printbinarytree(root->right, ofst);
	}
}
static void del(Node* root)
{
	delete root;
}
static int leftmost(Node* rootright)
{
	while (rootright->left != nullptr)
	{
		rootright = rootright->left;
	}
	return rootright->key;
}
static Node* replace(Node *root, int key)
{
	if (root == nullptr)
	{
		return nullptr;
	}
	if (root->key == key)
	{
		if (root->left == nullptr && root->right == nullptr)
		{
			del(root);
			return nullptr;
		}
		if (root->right == nullptr && root->left != nullptr)
		{
			Node* copy = root->left;
			del(root);
			return copy;
		}
		if (root->right != nullptr && root->left == nullptr)
		{
			Node* copy = root->right;
			del(root);
			return copy;
		}
		root->key = leftmost(root->right);
		root->right = replace(root->right, root->key);
		return root;
	}
	if (key < root->key)
	{
		root->left = replace(root->left, key);
		return root;
	}
	if (key > root->key)
	{
		root->right = replace(root->right, key);
		return root;
	}
	return root;
}
int main()
{
	ifstream ifst("input.txt");
	ofstream ofst("output.txt");
	Node* root = new Node;
	int delet{}, key{};
	ifst >> delet >> root->key;
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
	root = replace(root, delet);
	printbinarytree(root, ofst);
}