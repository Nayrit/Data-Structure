/*
 #include<iostream>
 #include<string>
 #include<stdlib.h>

 using namespace std;

 struct node
 {
     int data;
     node *next;


 };

 int main() {

      node obj1, obj2, obj3, obj4;

      obj1.data = 10;
      obj2.data = 20;
      obj3.data = 30;
      obj4.data = 40;

      obj1.next = NULL;
      obj2.next = NULL;
      obj3.next = NULL;
      obj4.next = NULL;


      obj1.next = &obj2;
      obj2.next = &obj3;
      obj3.next = &obj4;

      cout<<obj1.data<<" "<<obj1.next->data<<" "<<obj1.next->next->data<<" "<<obj1.next->next->next->data<<'\n';





    return 0;
 }
*/

#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;

struct node
{
    int data;
    node *next;


};

node *root = NULL; // store kore rakhbe linklist er suru ta kothai, always root theke suru korbo
void printing()
{

    node *current_node = root;
    while(current_node != NULL) //way 2 to stop
    {

        //if(current_node == NULL) break; //way 1 to stop

        cout<< current_node->data <<" ";

        //if(current_node == NULL) break; //way 3 to stop

        current_node = current_node->next;
    }
    cout<<endl;

}
void delete_first()
{
    root = root -> next;
}

void Last()
{

    node *current_node = root;
    while(true) //way 2 to stop
    {

        current_node = current_node->next;

        if(current_node->next == NULL)
        {
            cout<< current_node->data <<" ";
            break;
        } //way 1 to stop
        //if(current_node == NULL) break; //way 3 to stop
    }
}


int searching(int value)
{

    node *current_node = root;
    while(true) //way 2 to stop
    {

        current_node = current_node->next;

        if(current_node->data == value)
        {
            return 1;

        }
        if(current_node->next == NULL) break; //way 3 to stop
    }

    return -1;


}

void insert_first(int val)
{
    node *temp;
    temp = new node();
    temp -> data = val;
    temp -> next = NULL;

    if(root == NULL)
        root = temp;
    else
        temp -> next = root;
    root = temp;
}

void insert_last (int val)
{
    node *temp;
    temp = new node();
    temp -> data = val;
    temp -> next = NULL;

    if(root == NULL)
        root = temp;
    else
    {
        node *prev_node = NULL;
        node *curr_node = root;
        while(curr_node != NULL)
        {
            prev_node = curr_node;
            curr_node = curr_node -> next;
        }
        prev_node -> next = temp;
    }

}
void delete_last()           //same as insert_last, just temp changed to NULL
{
    //and while (curr_node -> next)
    node *prev_node = NULL;
    node *curr_node = root;
    while(curr_node -> next != NULL)
    {
        prev_node = curr_node;
        curr_node = curr_node -> next;
    }
    prev_node -> next = NULL;
}

void delete_any(int val)
{
    node *prev_node = NULL;
    node *curr_node = root;
    while(curr_node != NULL)
    {
        if(curr_node -> data == val)
            break;
        prev_node = curr_node;
        curr_node = curr_node -> next;
    }
    prev_node -> next = curr_node -> next;

}

void insert_any_front(int val, int p)
{
    node *temp;
    temp = new node();
    temp -> data = val;
    temp->next = NULL;
    if(root == NULL)
        root = temp;
    else
    {
        node *prev_node = NULL;
        node *curr_node = root;
        while(curr_node != NULL)
        {
            if(curr_node -> data == p)
                break;
            prev_node = curr_node;
            curr_node = curr_node -> next;
        }
        prev_node -> next = temp;
        temp -> next = curr_node;
    }
}
void insert_any_back(int val, int p)
{
    node *temp;
    temp = new node();
    temp -> data = val;
    temp->next = NULL;
    if(root == NULL)
        root = temp;
    else
    {
        node *prev_node = NULL;
        node *curr_node = root;
        while(curr_node != NULL)
        {
            if(curr_node -> data == p)
                break;
            prev_node = curr_node;
            curr_node = curr_node -> next;
        }
        prev_node -> next = temp;
        temp -> next = curr_node;
    }
}

int main()
{
    /*
        insert_first(10);
        insert_first(20);
        insert_first(30);
        insert_first(40);

        printing();
        cout<<endl;
        root = NULL;


        insert_last(10);
        insert_last(20);
        insert_last(30);
        insert_last(40);

        printing();
    */
    int x;
    for(int i=0; i<5; i++)
    {
        cin>>x;
        insert_first(x);
    }
    printing();
    //delete_any(40);
    //printing();

    insert_any_front(70,40);
    printing();



    /*    node *obj1, *obj2, *obj3, *obj4;

        obj1 = new node();
        obj2 = new node();
        obj3 = new node();
        obj4 = new node();

        obj1->data = 10;
        obj2->data = 20;
        obj3->data = 30;
        obj4->data = 40;

        obj1->next = NULL;
        obj2->next = NULL;
        obj3->next = NULL;
        obj4->next = NULL;


        obj1->next = obj2;  //& lagbe na cause sobai pointer
        obj2->next = obj3;
        obj3->next = obj4;

        root = obj1; // & dibo na cause duitai pointer

        printing();
        delete_first();
        printing();

        Last();

         cout<<obj1->data<<" "<<obj1->next->data<<" "<<obj1->next->next->data<<" "<<obj1->next->next->next->data<<'\n';

        int check = searching(40);

        if(check == 1)
            cout<<"Found\n";
        else
            cout<<"Not Found\n";
    */
    return 0;
}
