#include<bits/stdc++.h>
using namespace std;
int val = 35;
int cnt = 0;
struct node
{
    int data;
    node *left;
    node *right;
};
node *root = NULL;
void Insert(int value)
{
    node *temp = new node();
    temp -> data = value;
    temp -> left = NULL;
    temp -> right = NULL;
    if(root == NULL)
    {
        root = temp;
        return;
    }
    node *curr_node = root;
    node *prev_node = root;
    while(curr_node != NULL)
    {
        prev_node = curr_node;
        if(curr_node -> data < value)
            curr_node = curr_node -> right;
        else
            curr_node = curr_node -> left;
    }
    if(prev_node -> data < value)
        prev_node-> right = temp;
    else
        prev_node-> left = temp;
}
void inorder(node *dummy)
{
    if(dummy != NULL)
    {
        inorder(dummy -> left);
        cout<< dummy -> data <<" ";
        inorder(dummy -> right);
    }

}
void searching(node *root)
{
    if(root != NULL)
    {
        if(root -> data == val)
        {
            cnt = 1;
            return;
        }
        if(root -> data > val)
            searching(root -> left);
        if(root -> data < val)
            searching(root -> right);

    }
}
void minimum(node *dummy)
{
    if(dummy != NULL)
    {
        minimum(dummy -> left);
        if(dummy->left == NULL){
        cout<<"minimum: "<< dummy -> data <<" ";}
        //inorder(dummy -> right);
    }

}
void maximum(node *dummy)
{
    if(dummy != NULL)
    {
        maximum(dummy -> right);
        if(dummy->right == NULL){
        cout<<"maximum: " <<dummy -> data <<" ";}
        //inorder(dummy -> right);
    }

}
void delete_node(node *root)
{
    node *curr_node = root;
    node *prev_node = NULL;
    while(curr_node != NULL)
    {
        if(curr_node -> data == val)
            break;
        prev_node = curr_node;
        if(curr_node -> data < val)
            curr_node = curr_node -> right;
        else
            curr_node = curr_node -> left;
    }
    if(curr_node == NULL)
        return;
    if(curr_node -> left == NULL && curr_node -> right == NULL)
    {
        if(prev_node -> left == curr_node)
            prev_node -> left = NULL;
        else
            prev_node -> right = NULL;
        return;
    }
    if(curr_node -> left == NULL || curr_node -> right == NULL)
    {
        node *child;
        if(curr_node -> left == NULL)
            child = curr_node -> right;
        else
            child = curr_node -> left;
        if(prev_node == NULL)
            root == child;
        if(prev_node -> left == curr_node)
            prev_node -> left = child;
        else
            prev_node -> right = child;
    }
}
int main()
{
    Insert(61);
    Insert(54);
    Insert(35);
    Insert(28);
    Insert(40);
    Insert(59);
    Insert(78);
    Insert(63);
    Insert(82);
    Insert(85);
    //Insert(43);

    inorder(root);
    searching(root);
    cout<<endl;
    if(cnt ==1)
        cout<< "found";
    else
        cout<<"not found";
    cout<<endl;
    minimum(root);
    cout<<endl;
    maximum(root);
    cout<<endl;
    delete_node(root);
    inorder(root);

}
