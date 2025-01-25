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
    return 0;
}
// OUTPUT-
// 10 
// 10 12 
// 10 12 15 
// 22 10 12 15
//head 22
//tail 15 