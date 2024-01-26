#include <bits/stdc++.h>
using namespace std;
struct treeNode
{
    int val;
    treeNode* left;
    treeNode* right;
};
treeNode* newNode(int val)
{
    treeNode* node = new treeNode;
    node->val = val;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}
treeNode* per_bin_tree(int height, int val)
{
    if (height == 0)
    {
        return nullptr;
    }
    treeNode* root = newNode(val);
    root->left = per_bin_tree(height - 1, val * 2);
    root->right = per_bin_tree(height - 1, val * 2 + 1);
    return root;
}
void printing(treeNode* root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->val << " ";
    printing(root->left);
    printing(root->right);
}
int main()
{
    int height;
    cin>>height;
    treeNode* root = per_bin_tree(height, 1);
    printing(root);
    return 0;
}
