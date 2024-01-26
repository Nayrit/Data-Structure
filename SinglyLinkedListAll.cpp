#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next = NULL;
    node *prev = NULL;
};

node *root = NULL;
node *tail = NULL;

void insert_first(int val)
{
    node *temp = new node();
    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL;

    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        temp->next = root;
        root->prev = temp;
        root = temp;
    }
}

void insert_last(int val)
{
    node *temp = new node();
    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL;

    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        node *curr_node = root;
        node *prev_node = NULL;
        while (curr_node != NULL)
        {
            prev_node = curr_node;
            curr_node = curr_node->next;
        }
        prev_node->next = temp;
        temp->prev = prev_node;
        tail = temp;
    }
}

void insert_val_any(int val, int index)
{
    node *temp = new node();
    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL;

    if (root == NULL)
    {
        root = temp;
    }

    else if (index == 0)
    {
        temp->next = root;
        root->prev = temp;
        root = temp;
    }

    else
    {
        int cnt = 1;
        node *curr_node = root->next;
        node *prev_node = NULL;

        while (curr_node != NULL)
        {
            prev_node = curr_node;
            if (cnt == index)
            {
                break;
            }
            curr_node = curr_node->next;
            cnt++;
        }

        if (curr_node == NULL && (cnt == index))
        {
            prev_node->next = temp;
            temp->prev = prev_node;
            temp->next = NULL;
            tail = temp;
        }
        else if (index > cnt)
        {
            cout << "Invalid index\n";
        }
        else
        {
            node *prev_node_of_prev_node = prev_node->prev;
            prev_node_of_prev_node->next = temp;
            temp->prev = prev_node_of_prev_node;
            temp->next = prev_node;
            prev_node->prev = temp;
        }
    }
}

void delete_first()
{
    node *temp = root->next;
    temp->prev = NULL;
    root = temp;
}

void delete_last()
{
    tail = tail->prev;
    tail->next = NULL;
}

void delete_any(int value)
{
    node *curr_node = root;
    node *prev_node = NULL;

    while (curr_node != NULL)
    {
        if (value == curr_node->data)
        {
            break;
        }
        prev_node = curr_node;
        curr_node = curr_node->next;
    }
    if (prev_node == NULL) // if its root
    {
        root = root->next;
        root->prev = NULL;
    }
    else if (curr_node->next == NULL)
    {
        prev_node->next = NULL;
        tail = prev_node;
    }
    else
    {
        prev_node->next = curr_node->next;
        curr_node->next->prev = prev_node;
    }
}

void last_node()
{

    // while(curr_node -> next != NULL)
    // {
    //     curr_node = curr_node -> next;
    // }
    cout << "The last node is: ";
    cout << tail->data << "\n";
}

void printing()
{
    node *curr_node = root;
    while (curr_node != NULL)
    {
        cout << curr_node->data << " ";
        curr_node = curr_node->next;
    }
}

// reverse a singly linked list
void Fun(node *dummy)
{
    node *curr_node = dummy;

    if (dummy != NULL)
    {
        Fun(curr_node->next);
        cout << curr_node->data << " ";
    }
}

//Remove duplicate from a sorted linked list
void remove_dup(node *dummy)
{
    node *curr_node = dummy;
    while(curr_node != NULL)
    {
        if(curr_node -> data == curr_node -> next -> data)
        {
            curr_node -> next = curr_node -> next -> next;
        }
        curr_node = curr_node -> next;
    }
}

//Remove duplicates from an unsorted linked list
void remove_dup_from_unsorted_linked_list(node *dummy)
{
    node *curr_node = dummy;
    while(curr_node != NULL)
    {
        node *finder = curr_node -> next;

        while(finder != NULL)
        {
            if(curr_node -> data == finder -> data)
            {
                finder -> prev -> next = finder -> next;
            }
            finder = finder -> next;
        }
        curr_node = curr_node -> next;
    }
}

int main()
{
    // insert_last(10);
    // insert_last(30);
    // insert_last(20);

    insert_last(20);
    insert_last(20);
    insert_last(10);
    insert_last(30);
    insert_last(30);

    // insert_val_any(50, 3);
    // delete_first();
    // delete_any(50);

    // printing();
    // last_node();
    // delete_last();
    // cout << "\n";
    //Fun(root);
    //remove_dup(root);
    remove_dup_from_unsorted_linked_list(root);
    printing();
    cout << "\n";
    return 0;
}