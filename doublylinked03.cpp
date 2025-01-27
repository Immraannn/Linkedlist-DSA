#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*prev;
    Node*next;
    //constructor
    Node(int d){
        this->data=d;
        this->prev=NULL;//in starting
        this->next=NULL;//in starting
    }
    //destructor
    Node(){
        int val=this->data;
        if(next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"Memory is free for node with data "<<val<<endl;
    }
};
//traversing a linked list
void print(Node*&head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
//gives length of linkedlist
int getlength(Node*head){
    int len=0;
    Node*temp=head;
    while(temp!=NULL){
len++;
temp=temp->next;
    }
    return len;
}
void Insertionathead(Node*&head,int d){
    if(head==NULL){
        Node*temp=new Node(d);
        head=temp;
    }
   else{ Node*temp=new Node(d);
    temp->next=head;
    head->prev=temp;
    head=temp;
    }
}
void Insertionattail(Node*&tail,int d){
    if(tail==NULL){
        Node*temp=new Node(d);
        tail=temp;
    }
   else{ Node*temp=new Node(d);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
    }
}
void Insertatposition(Node*&tail,Node*&head,int position,int d){
   //insert to start
    if(position==1){
        Insertionathead(head,d);
        return ;
    }
    Node*temp=head;//creating a node and pointing it to head
    int cnt=1;
while(cnt<position){
    temp=temp->next;
    cnt++;
}
//insertion atlast position
if(temp->next==NULL){
    Insertionattail(tail,d);
    return;
}
//creating a node for d
Node*nodetoinsert=new Node(d);
nodetoinsert->next=temp->next;
temp->next->prev=nodetoinsert;
temp->next=nodetoinsert;
nodetoinsert->prev=temp;}
void deleteNode(int position,Node*&head){
    //deleting start or first node
    if(position==1){
        Node*temp=head;
        temp->next->prev=NULL;
        head=temp->next;
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
        curr->prev=NULL;
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
   


}
int main(){
    Node*node1=new Node(10);
    Node*head=node1;//pointing node 1 in starting
    Node*tail=node1;//pointing node 1 in starting
    print(head);
    cout<<getlength(head)<<endl;
    Insertionathead(head,11);
    Insertionathead(head,13);
    Insertionathead(head,8);
    Insertionattail(tail,25);
    print(head);
    Insertatposition(tail,head,1,100);
    Insertatposition(tail,head,2,19);
    print(head);
    deleteNode(7,head);
    print(head);
    return 0;
}
// OUTPUT-
// 10 
// 1
// 8 13 11 10 25
// 100 8 19 13 11 10 25
// 100 8 19 13 11 10
