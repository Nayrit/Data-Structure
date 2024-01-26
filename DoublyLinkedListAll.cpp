#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;
};

node *root = NULL;
node *tail = NULL;

void insert_first(int val)
{
    node *temp;
    temp = new node();
    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL;
    if (root == NULL)
        root = temp;
    else
    {
        temp->next = root;
        root->prev = temp; // Add
        root = temp;
    }
}

void insert_last(int val)
{
    node *temp;
    temp = new node();
    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL;
    if (root == NULL)
        root = temp;
    else
    {
        node *curr_node = root;
        node *prev_node = NULL;
        while (curr_node->next != NULL)
        {
            // prev_node = curr_node;//obj1, obj2
            curr_node = curr_node->next; // obj2, obj3, NULL
        }
        curr_node->next = temp;
        temp->prev = curr_node;
        tail = temp;
    }
}

void insert_val_any(int val, int index) // before a number;
{
    node *temp;
    temp = new node();
    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL;
    if (root == NULL)
        root = temp;
    else
    {
       
        node *curr_node = root;
        node *prev_node = NULL;
        if (index == 0)
        {
            curr_node->prev = temp;
            temp->next = curr_node;
            root = temp;
        }
        else
        {
            int cnt = 0;
            while (curr_node != NULL)
            {
                
                if (cnt == index)
                {
                    break;
                }
                
                prev_node = curr_node;
                curr_node = curr_node->next;
                cnt++;
            }
            if ((cnt + 1) == index)
            {
                curr_node->next = temp;
                temp->prev = curr_node;
                tail = temp;
            }
            else
            {
                // temp -> next = prev_node -> next;
                // temp -> prev = prev_node -> prev;//obj2.
                // prev_node -> prev = temp;
                // prev_node -> next = curr_node;
                
                temp -> next = prev_node -> next;
                temp -> prev = prev_node;
                prev_node -> next = temp; 
                
 
                if(temp->next != NULL)
                    temp -> next -> prev = temp;
                else if(temp->next == NULL)
                    tail = temp;
                
            }
        }
    }
}


void delete_first()
{
    root = root->next;
    root->prev = NULL; // to set the previous node of root as null.
    // tail = tail -> prev;
}

void delete_last()
{
    tail = tail->prev;
    tail->next = NULL;
}

void delete_any(int val)
{
    node *curr_node = root;
    node *prev_node = NULL;
    while (curr_node != NULL)
    {
        if (curr_node->data == val)
        {
            // curr_node = curr_node -> next -> next;
            break;
        }
        prev_node = curr_node;
        curr_node = curr_node->next;
    }
    prev_node->next = curr_node->next;
    node *post_node = NULL;
    curr_node = tail;
    while (curr_node != NULL)
    {
        if (curr_node->data == val)
        {
            // curr_node = curr_node -> prev -> prev;
            break;
        }

        post_node = curr_node;
        curr_node = curr_node->prev;
    }
    post_node->prev = curr_node->prev;
}

void last_node()
{
    node *curr_node = root;
    while (true)
    {
        curr_node = curr_node->next;
        if (curr_node->next == NULL)
        {
            cout << curr_node->data << " ";
            break;
        }
    }
    curr_node = tail;
    while(true)
    {
        curr_node = curr_node -> prev;
        if(curr_node -> prev == NULL)
        {
            cout << curr_node -> data << " ";
            break;
        }
    }
}

void printing()
{
    node *curr_node = root;
    while (curr_node != NULL)
    {
        cout << curr_node->data << " ";
        curr_node = curr_node->next;
    }
    // cout << "\n";
    curr_node = tail;
    while (curr_node != NULL)
    {
        cout << curr_node->data << " ";
        curr_node = curr_node->prev;
    }
}

int search(int val) // dont matter if you search from the start or ending.
{
    node *curr_node = root;
    while (curr_node != NULL)
    {
        if (curr_node->data == val)
        {
            cout << "Found\n";
            return -1;
        }
        curr_node = curr_node->next;
    }
    cout << "Not found\n";
    return 1;
}

int main()
{
    node *obj1, *obj2, *obj3; // Boxes created //Addresses
    obj1 = new node();
    obj2 = new node();
    obj3 = new node();

    // node obj2;
    // node obj3;
    obj1->data = 10; // Data of 3 boxes set.
    obj2->data = 20;
    obj3->data = 30;

    // Set null for address of each objects.
    obj1->next = NULL; // Or, just call it in structure once.
    obj2->next = NULL;
    obj3->next = NULL;

    // Set null for previous address of each objects.
    obj1->prev = NULL; // Or, just call it in structure once.
    obj2->prev = NULL;
    obj3->prev = NULL;

    // Now link all the boxes: LinkedList
    obj1->next = obj2;
    obj2->next = obj3;

    // Backward LinkedList:
    obj2->prev = obj1;
    obj3->prev = obj2;

    root = obj1;
    tail = obj3;

    // cout << obj3 -> data << " " << obj3 -> prev -> data << " " << obj3 -> prev -> prev -> data << "\n";
    printing();
    // delete_first();
    // cout << "\n";
    // printing();
    // search(20);
    // delete_last();
    cout << "\n";
    // printing();
    // delete_any(20);
    // printing();
    // cout << "\n";
    // insert_first(35);
    // printing();
    // cout << "\n";
    insert_val_any(27,2);
    
    printing();
    return 0;
}