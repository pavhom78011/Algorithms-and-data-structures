#include <iostream>
#include <fstream>
using namespace std;
struct Node
{
    int key{};
    Node* left = nullptr;
    Node* right = nullptr;
};
static Node* addel(Node* root, int key)
{
    if (root == nullptr)
    {
        Node* root = new Node;
        root->key = key;
        return root;
    }
    if (key < root->key)
    {
        root->left = addel(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = addel(root->right, key);
    }
    return root;
}
void printbinarytree(Node *root, ofstream &ofst)
{
    if (root != nullptr)
    {
        ofst << root->key << endl;
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
    Node b;
    while (ifst >> b.key)
    {
        addel(root, b.key);
    }
    printbinarytree(root, ofst);
}