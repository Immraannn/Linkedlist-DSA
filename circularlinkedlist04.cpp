#include<iostream>
using namespace std;
class Node{
public:
int data;
Node*next;
//constructor
Node(int d){
    this->data=d;
    this->next=NULL;
}
//Destructor
Node(){
    int value =this->data;
    if(this->next!=NULL){
        delete next;
        next=NULL;
    }
    cout<<"memory is free for node with data "<<value<<endl;
}
};
void InsertNode(Node*&tail,int element,int d){
    //empty list
    if(tail==NULL){
        Node*newNode=new Node(d);
        tail=newNode;
        newNode->next=newNode;
    }
    else{
        //non empty list
        //assuming that the element is present in the list
        Node*curr=tail;
        while(curr->data!=element){
            curr=curr->next;
        }
        //element found now  ->curr is represent element wala node
        Node*temp=new Node(d);
        temp->next=curr->next;
        curr->next=temp;
    }
}
void print(Node*tail){
    Node*temp=tail;
    do{
        cout<<tail->data<<" ";
        tail=tail->next;
    }while(tail!=temp);
    cout<<endl;
}
void deleteNode(Node*&tail,int value){
    //empty list
    if(tail==NULL){
        cout<<"List us empty ,please check again "<<endl;
        return;
    }
    else{
        //non-empty
        //assuming that value is present in cll
        Node*prev=tail;
        Node*curr=prev->next;
        while(curr->data!=value){
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        if(tail==curr){
            tail=prev;
        }
        curr->next=NULL;
        delete curr;
    }
}
int main(){
    Node*tail=NULL;
    //empty list mn insert kar rhe hn
    InsertNode(tail,5,3);
    print(tail);
    InsertNode(tail,3,5);
    print(tail);
    InsertNode(tail,5,7);
    print(tail);
    InsertNode(tail,7,9);
    print(tail);
    InsertNode(tail,5,6);
    print(tail);
    InsertNode(tail,3,5);
    print(tail);
    deleteNode(tail,3);
    print(tail);

        return 0;
}
// OUTPUT-
// 3 
// 3 5
// 3 5 7
// 3 5 7 9
// 3 5 6 7 9
// 3 5 5 6 7 9
// 9 5 5 6 7