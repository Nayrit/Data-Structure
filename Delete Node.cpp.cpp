#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};
node *root = NULL;
void inorder(node *dummy)
{
    if (dummy != NULL)
    {
        inorder(dummy->left);
        cout << dummy->data << endl;
        inorder(dummy->right);
    }
}
void insert(int value)
{
    node *temp = new node();
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    if (root == NULL)
    {
        root = temp;
        return;
    }
    node *curr_node = root;
    node *prev_node = root;
    while (curr_node != NULL)
    {
        prev_node = curr_node;
        if (curr_node->data < value)
            curr_node = curr_node->right;
        else
            curr_node = curr_node->left;
    }
    if (prev_node->data < value)
        prev_node->right = temp;
    else
        prev_node->left = temp;
}
void maximum()
{
    node *curr_node = root;
    node *prev_node = NULL;
    while (curr_node != NULL)
    {
        curr_node = curr_node->right;
        if (curr_node->right == NULL)
        {
            cout << curr_node->data << endl;
            break;
        }
    }
}
void minimum()
{
    node *curr_node = root;
    node *prev_node = NULL;
    while (curr_node != NULL)
    {
        curr_node = curr_node->left;
        if (curr_node->left == NULL)
        {
            cout << curr_node->data << endl;
            break;
        }
    }
}
void deleteNode(node *root, int val)
{
    node *curr_node = root;
    node *prev_node = NULL;
    while (curr_node != NULL)
    {
        if (curr_node->data == val)
            break;
        prev_node = curr_node;
        if (curr_node->data < val)
            curr_node = curr_node->right;
        else
            curr_node = curr_node->left;
    }
    if (curr_node == NULL)
        return;
                    // node with no child
    if (curr_node->left == NULL && curr_node->right == NULL)
    {
        if (prev_node->left == curr_node)
            prev_node->left = NULL;
        else
            prev_node->right = NULL;
        return;
    }
                    // node with one child
    if (curr_node->left == NULL || curr_node->right == NULL)
    {
        node *child;
        if (curr_node->left == NULL)
            child = curr_node->right;
        else
            child = curr_node->left;
        if (prev_node == NULL)
            root = child;
        if (prev_node->left == curr_node)
            prev_node->left = child;
        else
            prev_node->right = child;
    }
                    // node with two child
    else
    {
        node *temp = curr_node;
        prev_node = curr_node;
        curr_node = curr_node->right;
        while (curr_node->left != NULL)
        {
            prev_node = curr_node;
            curr_node = curr_node->left;
        }
        temp->data = curr_node->data;
        prev_node->left = curr_node->right;
    }
}
void search(node *root, int val)
{
    int count = 0;
    node *curr_node = root;
    node *prev_node = NULL;
    while (curr_node != NULL)
    {
        if (curr_node->data == val)
            count = 1;
        break;
        prev_node = curr_node;
        if (curr_node->data < val)
            curr_node = curr_node->right;
        if (curr_node->right->data == val)
            count = 1;
        else
            curr_node = curr_node->left;
        if (curr_node->left->data == val)
            count = 1;
    }
    if (count == 1)
        printf("found");
    else
        printf("not found");
}
int main()
{
    insert(12);
    insert(6);
    insert(18);
    insert(4);
    insert(9);
    insert(16);
    insert(49);
    insert(5);
    insert(10);
    insert(31);
    insert(33);
    inorder(root);
    search(root, 12);
    cout << endl;
    cout << "minimum";
    minimum();
    cout << endl;
    cout << "maximum";
    maximum();
    deleteNode(root, 12);
    inorder(root);
    search(root, 12);
}
