#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left = NULL;
    node *right = NULL;
};

node *root = NULL;

void Insert(int value)
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

void in_order(node *dummy)
{
    if (dummy != NULL)
    {
        in_order(dummy->left);
        cout << dummy->data << " ";
        in_order(dummy->right);
    }
}

void search(node *dummy, int val)
{
    node *curr_node = root;
    node *prev_node = NULL;

    while (curr_node != NULL)
    {
        if (curr_node->data == val)
        {
            cout << "Found\n";
            return;
        }
        else if (curr_node->data < val)
        {
            curr_node = curr_node->right;
        }
        else
        {
            curr_node = curr_node->left;
        }
    }
    if (curr_node == NULL)
    {
        cout << "Not found\n";
        return;
    }
}

void minimum(node *dummy)
{
    node *curr_node = root;
    node *prev_node = NULL;

    int min_val = 9999;

    while (curr_node != NULL)
    {
        if (curr_node->data < min_val)
        {
            prev_node = curr_node;
            min_val = curr_node->data;
            curr_node = curr_node->left;
        }
        // else
        // {
        //     prev_node = curr_node;
        //     // curr_node = curr_node -> right;
        // }
    }
    if (curr_node == NULL)
    {
        cout << "Min value: " << min_val << endl;
        return;
    }
}

void maximum(node *dummy)
{
    node *curr_node = root;
    node *prev_node = NULL;

    int max_val = 0;

    while (curr_node != NULL)
    {
        if (curr_node->data > max_val)
        {
            prev_node = curr_node;
            max_val = curr_node->data;
            curr_node = curr_node->right;
        }
        // else
        // {
        //     prev_node = curr_node;
        //     // curr_node = curr_node -> right;
        // }
    }

    cout << "Max value: " << max_val << endl;
    return;
}

node *Delete_Node(node *root, int val)
{
    if (root->data > val)
    {
        root->left = Delete_Node(root->left, val);
    }
    else if (root->data < val)
    {
        root->right = Delete_Node(root->right, val);
    }
    else
    {
        if (!root->left && !root->right)
        {
            delete root;
            root = NULL;
        }
        else if (!root->left)
        {
            node *temp = root;
            root = root->right;
            delete temp;
        }
        else if (!root->right)
        {
            node *temp = root;
            root = root->left;
            delete temp;
        }
        else
        {
            node *temp = root->right;
            while (temp->left)
            {
                temp = temp->left;
            }
            root->data = temp->data;
            root->right = Delete_Node(root->right, temp->data);
        }
    }
    return root;
}

void deleteNode(node *root, int val)
{
    node *curr_node = root, *prev_node = NULL;
    while(curr_node != NULL)
    {
        if(curr_node -> data == val)break;
        prev_node = curr_node;
        if(curr_node -> data < val)curr_node = curr_node -> right;
        else curr_node = curr_node -> left;
    }

    if(curr_node == NULL)return;

    //node found with less than two children
    if(curr_node -> left == NULL && curr_node -> right == NULL)
    {
        if(prev_node -> left == curr_node)prev_node -> left = NULL;
        else
        {
            prev_node -> right = NULL;
        }
        return;
    }

    if(curr_node -> left == NULL || curr_node -> right == NULL)
    {
        node *child;
        if(curr_node -> left == NULL)child = curr_node -> right;
        else child = curr_node -> left;

        if(prev_node == NULL)root = child;
        else if(prev_node -> left == curr_node)prev_node -> left = child;
        else prev_node -> right = child;

    }

    //node found with both children
    else
    {
        node *temp = curr_node;//18
        prev_node = curr_node;//18
        curr_node = curr_node -> right;//40

        while(curr_node -> left != NULL)
        {
            prev_node = curr_node;//40, 37, 28
            curr_node = curr_node -> left;//37, 28, 25, NULL(ar to dhukbei na)

        }
        temp -> data = curr_node -> data;//25
        if(prev_node -> left == curr_node)
        {
            prev_node -> left = curr_node -> right;
        }
        else
        prev_node -> right = curr_node -> right;

    }
}

int main()
{
    Insert(12);
    Insert(6);
    Insert(18);
    Insert(40);
    Insert(17);
    Insert(37);
    Insert(28);
    Insert(25);
    //Delete_Node(root, 18);
    deleteNode(root, 18);
    in_order(root);
    cout << "\n";
    search(root, 25);
    cout << "\n";
    minimum(root);
    cout << "\n";
    maximum(root);
    cout << "\n";
}
