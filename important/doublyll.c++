#include<iostream>
using namespace std;

class Node{
    public:
    int value;
    Node* next;
    Node* prev;
};
void printforward(Node* head){
    Node* traverse=head;

    while(traverse!=NULL){
        cout<<traverse->value<<"->";
        traverse=traverse->next;
    }
}
void printbackward(Node* tail){
    Node* traverse=tail;

    while(traverse!=NULL){
        cout<<traverse->value<<"->";
      
        traverse=traverse->prev;
    }
     cout << "NULL" << endl; 
}
void insertatlast(Node** head, Node** tail, int newvalue) {
    Node* newnode = new Node();

    newnode->value = newvalue;
    newnode->next = nullptr;

    if (*head == nullptr) {
        // If the list is empty, set both head and tail to the new node
        newnode->prev = nullptr;
        *head = newnode;
        *tail = newnode;
        return;
    }

    Node* last = *tail;
    last->next = newnode;
    newnode->prev = last;
    *tail = newnode;
}


void deletenode(Node** head,Node** tail,int del){
    if(*head==nullptr){
        cout<<"NULL";
        return;
    }

    Node* current=*head;

    while(current != nullptr && current->value != del){
        current=current->next;
    }

    if(current==nullptr){
        cout<<"No";
        return;
    }

    if(current->prev!=nullptr){
        current->prev->next=current->next;
    }else{
        *head=current->next;
    }

    if(current->next != nullptr){
        current->next->prev=current->prev;
    }else{
        *tail=current->prev;
    }

    delete current;
    current=nullptr;
}

int main(){
    Node* head;
    Node* tail;

    Node* node=new Node();
    node->value=1;
    node->next=nullptr;
    node->prev=nullptr;
    head=node;
    tail=node;

    node=new Node();
    node->value=2;
    node->next=nullptr;
    node->prev=tail;
    tail->next=node;
    tail=node;

    node=new Node();
    node->value=3;
    node->next=nullptr;
    node->prev=tail;
    tail->next=node;
    tail=node;
  
    printforward(head);
 
    insertatlast(&head,&tail,4);
    deletenode(&head,&tail,3);
    printforward(head);
   
    printbackward(tail);
 }