#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node *prev;

    Node(int val){
        data=val;
        prev=next=NULL;
    }
};
class Doubly{
    private:
    Node* head;

    public:
    Doubly(){
        head=NULL;
    }

    void insertFront(int val) {
        Node* newNode =new Node(val);

        if (head!=NULL) {
            head->prev=newNode;
            newNode->next=head;
        }

        head=newNode;
    }
    void insertAtPosition(int val,int pos) {
    Node* newNode=new Node(val);
    if(pos==1){
        insertFront(val);
        return;
    }
    Node* temp=head;

    for(int i=1;i<pos-1&&temp!=NULL;i++) {
        temp =temp->next;
    }

    if(temp==NULL){
        cout<<"Position out of range\n";
        return;
    }
    newNode->next=temp->next;
    newNode->prev=temp;
    if(temp->next!=NULL)
        temp->next->prev =newNode;

    temp->next =newNode;
}

void deleteAtPosition(int pos){
    if(head==NULL){
        cout<<"List is empty\n";
        return;
    }

    Node* temp=head;

    if(pos==1){
        head=head->next;
        if(head!=NULL)
            head->prev =NULL;
        delete temp;
        return;
    }

    for (int i=1;i<pos&&temp!= NULL;i++) {
        temp =temp->next;
    }

    if(temp==NULL){
        cout<<"Position out of range\n";
        return;
    }

    if(temp->prev!=NULL)
        temp->prev->next =temp->next;

    if(temp->next!=NULL)
        temp->next->prev =temp->prev;


    delete temp;
}

 void displayFor(){
        Node* temp =head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

    
    void displayBack() {
        if(head==NULL) 
        return;

        Node* temp=head;
        while(temp->next!=NULL)
            temp =temp->next;

        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->prev;
        }
        cout<<endl;
    }

};
int main() {
    Doubly dl;

    dl.insertFront(30);
    dl.insertFront(20);
    dl.insertFront(10);

    cout<<"List after inserting at front:";
    dl.displayFor();

    dl.insertAtPosition(15,2);
    dl.insertAtPosition(5,1);
    cout<<"After inserting 5 at position 1 and 15 at position 2: ";
    dl.displayFor();

    dl.deleteAtPosition(3);
    cout<<"After deleting position 3:";
    dl.displayFor();

    cout<<"Display in reverse: ";
    dl.displayBack();

    return 0;
}