#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *root = NULL;
void Insert_First(int value)
{
    node *temp = new node();
    temp->data = value;
    temp->next = NULL;
    if( root == NULL)
    {
        root = temp;
    }
    else
    {
        temp->next = root;
        root = temp;
    }
}

void Insert_Last(int value)
{
    node *temp = new node();
    temp->data = value;
    temp->next = NULL;
    if(root == NULL)
    {
        root = temp;
    }
    else
    {
        node *pre_node = NULL;
        node *current_node = root;
        while(current_node != NULL)
        {
            pre_node = current_node;
            current_node = current_node->next;
        }
        pre_node->next = temp;
    }
}

void Printing()
{
    node * current_node = root;
    cout<<"\n\nThe LinkedList:\t";
    while(current_node != NULL)
    {
        cout<<current_node->data<<"\t";
        current_node = current_node->next;
    }
    cout<<"\n\n";
}

void Size()
{
    cout<<"\n\n";
    int count = 0;
    node *current_node = root;
    while(true)
    {
        count++;
        if(current_node->next == NULL)
        {
            break;
        }
        current_node = current_node->next;
    }
    cout<<"Number of Elements: "<<count<<"\n\n";
}

void Last()
{

    node *current_node = root;
    cout<<"The Last Index: ";
    while(true)
    {
        current_node = current_node->next;
        if(current_node->next == NULL)
        {
            cout<< current_node->data <<" ";
            break;
        }
    }
    cout<<"\n\n";
}

void Delete_First()
{
    root = root->next;
}

void Delete_Last()
{
    node *pre_node = NULL;
    node *current_node = root;
    while(current_node->next != NULL)
    {
        pre_node = current_node;
        current_node = current_node->next;
    }
    pre_node->next = NULL;
}

void Delete_AnyValue(int value)
{
    node *pre_node = NULL;
    node *current_node = root;
    while(true)
    {
        if(current_node->data == value)
        {
            pre_node->next = current_node->next;
            break;
        }
        pre_node = current_node;
        current_node = current_node->next;
    }
}

void Delete_AnyWhere(int Position)
{
    node *pre_node = NULL;
    node *current_node = root;
    int check = 0 ;
    while(true)
    {
        check++;
        if(check == Position)
        {
            pre_node->next = current_node->next;
            break;
        }
        pre_node = current_node;
        current_node = current_node->next;

    }
}

void Searching(int value)
{

    cout<<"\n\n";
    node *current_node = root;
    int check = 0;
    while(true)
    {
        if(current_node->data == value)
        {
            cout<<value<<" is Found\n\n";
            check++;
            break;
        }
        if(current_node->next == NULL)
            break;
        current_node = current_node->next;
    }
    if(check == 0)
        cout<<"Value Not Found\n\n";
}

void Number_Of_Occurance(int value)
{
    cout<<"\n\n";
    node *current_node = root;
    int count = 1;
    while(true)
    {
        if(current_node->data == value)
            count++;
        if(current_node->next == NULL)
            break;
        current_node = current_node->next;
    }
    cout<<value<<" occurs "<<count<<" time\n\n";
}

void Nth_Position_Value(int position)
{
    cout<<"\n\n";
    node *current_node = root;
    int check = 0, count = 0;
    while(true)
    {
        count++;
        if(count == position)
        {
            cout<<"Value in position "<<position<<" is "<<current_node->data<<"\n\n";
            check++;
            break;
        }
        if(current_node->next == NULL)
            break;
        current_node = current_node->next;
    }
    if(check == 0)
    {
        cout<<"Position doesn't exist.\n\n";
    }
}

void Reversing_Singly_LinkedList(node *current_node)
{
    if(current_node != NULL)
    {
        Reversing_Singly_LinkedList(current_node->next);
        cout<<current_node->data<<"\t";
    }
}

int main()
{
    int size,input;
    cout<<"\n\nEnter the size of the LinkedList : ";
    cin>>size;
    cout<<"Enter the elements: \n";
    for (int i = 0; i < size; i++)
    {
        cin>>input;
        Insert_Last(input);
    }
    //Size();
    //Last();
    //Delete_Last();
    //Delete_First();
    //Delete_First();
    //Delete_AnyValue(50);
    //Delete_AnyWhere(5);
    //Searching(50);
    //Number_Of_Occurance(30);
    //Nth_Position_Value(5);
    //Reversing_Singly_LinkedList(root);
    Printing();
    return 0;
}
