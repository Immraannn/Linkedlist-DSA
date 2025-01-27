#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    //constructor
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
    //destructor
    Node(){
        int value=this->data;
        //memoryfree
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"Memory is freed for node with data "<<endl;
    }

};
void Insertionathead(Node *&head,int d){
//new node create
Node* temp=new Node(d);
temp->next=head;
head=temp;
    }
void Insertionattail(Node *&tail,int d){
//new node create
Node* temp=new Node(d);
tail->next=temp;
tail=temp;
    }
void Insertatposition(Node*&tail,Node*&head,int position,int d){
    //inserting at start
    if(position==1){
        Insertionathead(head,d);
        return;
    }
    Node*temp=head;
    int cnt=1;
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }
    //inserting at last position
    if(temp->next==NULL){
        Insertionattail(tail,d);
    }
    //creating a node for d
    Node*nodetoinsert=new Node(d);
    nodetoinsert->next=temp->next;
    temp->next=nodetoinsert;
}    
void print(Node*&head){
        Node*temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
void deleteNode(int position,Node*&head){
    //deleting start or first node
    if(position==1){
        Node*temp=head;
        head=head->next;
        //memory free start node
        temp->next=NULL;
        delete temp;
    }
    else{
        //deleting any middle or last node
        Node*curr=head;
        Node*prev=NULL;
        int cnt=1;
        while(cnt<position){
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}    

int main(){
    //creation a new node
    Node* node1=new Node(10);
    Node*head=node1;
    Node*tail=node1;
    print(head);
    Insertionattail(tail,12);
    print(head);
    Insertionattail(tail,15);
print(head);
Insertatposition(tail,head,1,22);
print(head);
cout<<"head "<<head->data<<endl;
cout<<"tail "<<tail->data<<endl;
deleteNode(4,head);
print(head);
    return 0;
}
// OUTPUT-
// 10 
// 10 12 
// 10 12 15 
// 22 10 12 15
//head 22
//tail 15 
//22 10 12
