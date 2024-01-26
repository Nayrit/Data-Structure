#include<bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node *next;
};
node *root = NULL;

void push(int value) {
    node *temp = new node();
    temp->data = value;
    temp->next = NULL;
    if( root == NULL)
        root = temp;
    else {
        temp->next = root;
        root = temp;
    }
}

void pop() {

    root = root->next;
}

int sizel() {
    cout<<"\n\n";
    int count = 0;
    node *current_node = root;
    while(current_node != NULL) {
        count++;
        
        current_node = current_node->next;
    }
        return count;
}
void top(int position) {
    cout<<"\n\n";
    node *current_node = root;
    int check = 0, count = 0;
    while(true) {
        count++;
        if(count == position){
            cout<<"Value in position "<<position<<" is "<<current_node->data<<"\n\n";
            check++;
            break;
        }
        if(current_node->next == NULL)
            break;
        current_node = current_node->next;
    }
    if(check == 0){
        cout<<"Position doesn't exist.\n\n";
    }
}
void Printing() {
    node * current_node = root;
    cout<<"\n\nThe LinkedList:\t";
    while(current_node != NULL) {
        cout<<current_node->data<<"\t";
        current_node = current_node->next;
    }
    cout<<"\n\n";
}
void empty(){
    cout<<"\n\n";
    int count = 0;
    node *current_node = root;
    while(true) {
        count++;
        if(current_node->next == NULL)
            break;
        current_node = current_node->next;
    }
    if(count == 0){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
}
int main() {
    int n,input;
    cout<<"\n\nEnter the size of the LinkedList : ";
    cin>>n;
    cout<<"Enter the elements: \n"; 
    for (int i = 0; i < n; i++)
    {
        cin>>input;
        push(input);
        pop();
    }
    //cout<<sizel();
    //int u = sizel();
    //pop();
    //pop();
    //top(1);
    //pop();
    //pop();
    //pop();
    int b=sizel();
    if(b==0){
        cout<<"Underflow"<<endl;
        return 0;
}
    Printing();
    pop();
    Printing();
    top(1);
    sizel();
    empty();
    return 0;
}