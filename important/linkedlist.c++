#include<iostream>
using namespace std;

class Node{
    public:
    int value;
    Node* next;
};
void printlist(Node* n){
    while(n!=NULL){
        cout<<n->value<<"->";
        n=n->next;
    }

}
void insertnodeatfront(Node** head,int newvalue){
    Node* newnode=new Node();
    newnode->value=newvalue;
    newnode->next=*head;
    *head=newnode;
}
void insertnodeatend(Node** head,int newvalue){
    Node* newnode=new Node();
    newnode->value=newvalue;
    newnode->next=NULL;

    if(*head==NULL){
        *head=newnode;
        return;
    }

    Node* last=*head;
    while(last->next!=NULL){
        last=last->next;
    }

    last->next=newnode;

}
void insertafter(Node* previous,int newvalue){
    if(previous==NULL){
        cout<<"Cant be null";
        return;
    }
    Node* newnode=new Node();
    newnode->value=newvalue;
    newnode->next=previous->next;
    previous->next=newnode;

}
void reverse(Node** head){
    Node* current = *head;
    Node *prev=NULL;
    Node *next=current->next;

    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    *head=prev;
}
Node* deletelast(Node* head){
    if(head==NULL){
        return NULL;
    }

    if(head->next==NULL){
       delete head;
       return NULL;
    }

    Node* second=head;
    while(second->next->next!=NULL){
        second=second->next;
    }

    delete(second->next);
    second->next=NULL;
    return head;
}

void middle(Node* head){
    Node* slow=head;
    Node* fast=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }

    cout<<slow->value<<" ";
}

void detectloop(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            cout << "loop detected";
            return;
        }
    }

    cout << "no loop";
}


void deleteEvenIndexNodes(Node** head) {
    Node* current = *head;
    Node* prev = nullptr;
    int index = 0;

    while (current != nullptr) {
        if (index % 2 == 0) {
            // If the current node is at an even index, delete it
            Node* temp = current;

            if (prev != nullptr) {
                prev->next = current->next;
            } else {
                // If the even-indexed node is the first node, update the head
                *head = current->next;
            }

            current = current->next;
            delete temp;
        } else {
            // If the current node is at an odd index, move to the next node
            prev = current;
            current = current->next;
        }

        index++;
    }
}
int main() {
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    head->value = 1;
    head->next = second;
    second->value = 2;
    second->next = third;
    third->value = 3;
    third->next = head; // Creating a loop by connecting the last node to the head
    // insertnodeatfront(&head, -1);
    // insertnodeatend(&head, 4);
    // insertnodeatend(&head, 6);
    // insertnodeatend(&head, 7);

    // printlist(head);
    // reverse(&head);
    // deletelast(head);
    detectloop(head);
    // middle(head);
    // printlist(head);

    return 0;
}