#include<bits/stdc++.h>
using namespace std;
struct treeNode
{
    int val;
    treeNode* left;
    treeNode* right;
};
treeNode* com_bin_tree(int arr[], int i, int n)
{
    if (i > n)
        return nullptr;
    treeNode* node = new treeNode;
    node->val = arr[i-1];
    node->left = com_bin_tree(arr, 2*i, n);
    node->right = com_bin_tree(arr, 2*i+1, n);
    return node;
}
void printing(treeNode* root)
{
    if (root == nullptr)
        return;
    cout << root->val << " ";
    printing(root->left);
    printing(root->right);
}
int main()
{
    int n, arr[10];
    cin>>n;
    for(int i =0; i<n; i++)
        cin>>arr[i];
    treeNode* root = com_bin_tree(arr, 1, n);
    printing(root);
    return 0;
}
