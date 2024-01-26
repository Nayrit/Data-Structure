#include<bits/stdc++.h>
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
    if(dummy != NULL)
    {
        inorder(dummy -> left);
        cout<< dummy -> data <<" ";
        inorder(dummy -> right);
    }

}
void preorder(node *dummy)
{
    if(dummy != NULL)
    {
        cout<< dummy -> data <<" ";
        preorder(dummy -> left);
        preorder(dummy -> right);
    }

}
void postorder(node *dummy)
{
    if(dummy != NULL)
    {
        postorder(dummy -> left);
        postorder(dummy -> right);
        cout<< dummy -> data <<" ";
    }

}
int main()
{
    node *obj1, *obj2, *obj3,*obj4,*obj5,*obj6,*obj7;

    obj1 = new node();
    obj2 = new node();
    obj3 = new node();
    obj4 = new node();
    obj5 = new node();
    obj6 = new node();
    obj7 = new node();

    obj1 -> left = NULL;
    obj2 -> left = NULL;
    obj3 -> left = NULL;
    obj4 -> left = NULL;
    obj5 -> left = NULL;
    obj6 -> left = NULL;
    obj7 -> left = NULL;

    obj1 -> right = NULL;
    obj2 -> right = NULL;
    obj3 -> right = NULL;
    obj4 -> right = NULL;
    obj5 -> right = NULL;
    obj6 -> right = NULL;
    obj7 -> right = NULL;

    obj1 -> data = 10;
    obj2 -> data = 15;
    obj3 -> data = 11;
    obj4 -> data = 25;
    obj5 -> data = 51;
    obj6 -> data = 30;
    obj7 -> data = 19;

    obj1 -> left = obj2;
    obj1 -> right = obj3;
    obj2 -> left = obj4;
    obj2 -> right = obj5;
    obj3 -> left = obj6;
    obj3 -> right = obj7;

    root = obj1;
    cout<<"inorder: ";
    inorder(root);
    cout<<endl<<"preorder: ";
    preorder(root);
    cout<<endl<<"postorder: ";
    postorder(root);

}
