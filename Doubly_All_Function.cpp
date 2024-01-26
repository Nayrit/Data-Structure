#include<iostream>

using namespace std;

struct node{

    int data;
    node *next;
    node *previous_node;
};

node *root = NULL;
node *tail = NULL;

void Printing() {

    cout<<"\n\n";

    node *current_node = root;
    cout<<"Elements of the LinkedList-->Forward: ";
    while(true) {

        cout<<current_node->data<<" ";

        if(current_node->next == NULL){
            break;
        }
        
        current_node = current_node->next;
    }
    

    cout<<"\n\n";

    current_node = tail;

    cout<<"Elements of the LinkedList-->Reverse: ";
    while(true) {

        cout<<current_node->data<<" ";

        if(current_node->previous_node == NULL){
            break;
        }
        
        current_node = current_node->previous_node;
    }
    cout<<"\n\n";
}



void Insert_First(int value) {

    node *temp = new node();

    temp->data = value;
    temp->next = NULL;
    temp->previous_node = NULL;

    if( root == NULL){
        
        root = temp;
        tail = root;
    }
    else {

        temp->next = root;
        root->previous_node = temp;
        root = temp;
    }
}



void Insert_Last(int value) {

    node *temp = new node();

    temp->data = value;
    temp->next = NULL;
    temp->previous_node = NULL;

    tail = temp;

    if(root == NULL) {

        root = temp;
        root->previous_node = NULL;
    }

    else{

        node *pre_node = NULL;
        node *current_node = root;
        while(current_node != NULL) {

            pre_node = current_node;
            current_node = current_node->next;

        } 
        temp->previous_node = pre_node;
        pre_node->next = temp;
        
    }

}

void Sorted_LinkedList(int value) {

    int count = 0;

    node *temp = new node();

    temp->data = value;
    temp->next = NULL;
    temp->previous_node = NULL;

    if(root == NULL){
        root = temp;
        tail = temp;
    }
    else{
        node *current_node = root;
        node *previous_node = root;

        while(true) {


            if(root->data >= value){

                root->previous_node = temp;
                temp->next = root;
                root = temp;
                break;
            }

            else if(current_node->data >= value){

                temp->next = current_node;
                current_node->previous_node = temp;
                previous_node->next = temp;
                count++;
                break;
            }

            if(current_node->next == NULL and count == 0){

                
                
                current_node->next = temp;
                temp->previous_node = current_node;
                tail = temp;
                break;
            }


            previous_node = current_node;
            current_node = current_node->next;
        }
    }
}

void Delete_First() {

    root = root->next;
    root->previous_node = NULL;
}



void Delete_Last() {

    tail = tail->previous_node;
    tail->next = NULL;

}



void Insert_AnyWhere(int value, int Position) {

        node *temp = new node();

        temp->data = value;
        temp->next = NULL;
        temp->previous_node = NULL;


        node *pre_node = NULL;
        node *current_node = root;

        int count = 0 ,check = 0, nullchecker = 1;
        while(current_node != NULL) {

            count++;

            if(Position == 1) {

                temp->next = root;
                root->previous_node = temp;
                root = temp;

                check++;
                break;
            }

            else if (current_node->next == NULL and (count == Position || (count+1)== Position))
            {
                current_node->next = temp;
                temp->previous_node = current_node;
                tail = temp;
                check++;
                break;
            }
            

            else if(count == Position){

                temp->next = pre_node->next;
                pre_node->next = temp; 
                temp->previous_node = pre_node;

                if(temp->next != NULL)
                    temp->next->previous_node = temp;
                if(temp->next == NULL)
                    tail = temp;

                check++;
                break;
            }

            pre_node = current_node;
            current_node = current_node->next;

        }

    if(check == 0){
        
        cout<<"\n\nPosition doesn't Exit. Sorry!!!\n\n\n";
    }
    
}



void Insert_anywhere(int value, int checker) {

    node *temp = new node();

    temp->data = value;
    temp->next = NULL;
    temp->previous_node = NULL;

    node *pre_node = NULL;
    node *current_node = root;
    int count = 0 ,check = 0;
    
    while(true) {

        if(current_node->data == checker) {

            if(current_node->previous_node == NULL){
                
                temp->next = current_node;
                current_node->previous_node = temp;
                root = temp;
                check++;
                break;
            }

            temp->next = pre_node->next;
            temp->previous_node = pre_node;
            pre_node->next = temp;
            current_node->previous_node = temp;
            check++;
            break;
        }
        if(current_node->next == NULL and check == 0){
            cout<<"\n\nValue doesn't exist in the linkedList.\n\n\n";
            break;
        }

        pre_node = current_node;
        current_node = current_node->next;
    }

}



void Size() {

    cout<<"\n\n";
    int count = 0;
    node *current_node = root;

    while(true) {

        count++;
        if(current_node->next == NULL){
            break;
        }
        
        current_node = current_node->next;
    }
    cout<<"Number of Elements: "<<count<<"\n\n";
}



void Last() {

    node *current_node = root;
    cout<<"The Last Index: ";
    while(true){

        current_node = current_node->next;

        if(current_node->next == NULL){
            cout<< current_node->data <<" ";
            break;
        }        
    }
    cout<<"\n\n";
}



void Delete_AnyValue(int value) {

        node *pre_node = NULL;
        node *current_node = root;
        while(true) {

            if(current_node->data == value){

                if(current_node->next == NULL){

                    tail = pre_node;
                }
                else
                    current_node->next->previous_node = pre_node;

                pre_node->next = current_node->next;
                break;
            }

            pre_node = current_node;
            current_node = current_node->next;

        }
}



void Delete_AnyWhere(int position) {

    node *pre_node = NULL;
    node *current_node = root;
    int check = 0;
    while(true) {

        check++;

        if(check == position){

            if(current_node->next == NULL){

                tail = pre_node;
            }
            else
                current_node->next->previous_node = pre_node;

            pre_node->next = current_node->next;
            break;
        }
        
        pre_node = current_node;
        current_node = current_node->next;

    }
}



void Searching(int value) {

    cout<<"\n\n";
    node *current_node = root;
    int check = 0;
    while(true) {

        if(current_node->data == value){
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



void Number_Of_Occurance(int value) {

    cout<<"\n\n";

    node *current_node = root;
    int count = 0;

    while(true) {

        if(current_node->data == value) 
            count++;

        if(current_node->next == NULL) 
            break;

        current_node = current_node->next;

    }
    cout<<value<<" occurs "<<count<<" time\n\n";
}



void Nth_Position_Value(int position) {

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



void Reversing_Singly_LinkedList(node *current_node) {

    if(current_node != NULL) {


        Reversing_Singly_LinkedList(current_node->next); 

        cout<<current_node->data<<"\t";
    }
}



void Deleting_Last_Occurance(int value) {

    node *current_node = root;

    int position = 0 ;
    int count = 0 ;
    while(true){

        count++; 

        if(current_node->data == value){
            
            position = count;
        }
        if(current_node->next == NULL) {

            break;
        }
        current_node = current_node->next;

    }

    Delete_AnyWhere(position);    
}



int main() {

    int size,input;
    cout<<"\n\nEnter the size of the LinkedList : ";
    cin>>size;

    cout<<"Enter the elements: \n"; 
    for (int i = 0; i < size; i++)
    {
        cin>>input;
        Insert_Last(input);
    }

    //Delete_First();
    //Delete_Last();
    //Delete_AnyValue(50);
    //Delete_AnyWhere(5);
    //Insert_AnyWhere(5,6);
    //Insert_anywhere(5,70);
    //Deleting_Last_Occurance(4);
    //Printing();
    //Reversing_Singly_LinkedList(root);
    //Nth_Position_Value(5);
    //Number_Of_Occurance(20);
    //Searching(80);
    //Size();
    //Last();
}