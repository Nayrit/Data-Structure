#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
    node *prev;
};
node *root = NULL;
node *tail = NULL;


void printing(){
    cout<<endl;
    node *curr_node = root;
    cout<< "frontwards: ";
    while(curr_node != NULL){
        cout<<curr_node -> data<< " ";
        curr_node = curr_node -> next;
    }
    cout<<endl;
    cout<< "Backwards: ";
    curr_node = tail;
    while(curr_node != NULL){
        cout<<curr_node -> data<< " ";
        curr_node = curr_node -> prev;
    }
}
void delete_first()
{
    root = root -> next;
    root -> prev = NULL;
}

void delete_last()
{
    tail = tail -> prev;
    tail -> next = NULL;
}
void insert_any()

int main(){
    node *obj1, *obj2, *obj3;

    obj1 = new node();
    obj2 = new node();
    obj3 = new node();

    obj1->data = 10;
    obj2->data = 20;
    obj3->data = 30;

    obj1->next = NULL;
    obj2->next = NULL;
    obj3->next = NULL;

    obj1->next = obj2;
    obj2->next = obj3;

    obj1->prev = NULL;
    obj2->prev = NULL;
    obj3->prev = NULL;

    obj2->prev = obj1;
    obj3->prev = obj2;

    root = obj1;
    tail = obj3;

    printing();
    //delete_last();
    //printing();

    delete_any(20);
    printing();

    return 0;
}
