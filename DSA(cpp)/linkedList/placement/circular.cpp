#include<iostream>
using namespace std;

class Node{
    public:

    int data;
    Node*next;
    Node(int data){
        this->data=data;
        this->next=NULL;

    }

};

Node* fromArr(int arr[],int n){
    Node*tail=new Node(arr[0]);
    Node*mover=tail;
    for(int i=1;i<n;i++){
        Node*temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    mover->next=tail;// to connect
    return tail;

}




void insert(Node*tail,int ele,int data){
    if(tail==NULL){
        Node*temp=new Node(data);
        tail=temp;
        tail->next=tail;// to connect 
    }
    else{
        Node*countTemp=tail;
        while(countTemp->data!=ele){
            countTemp=countTemp->next;

        }
        Node*temp=new Node(data);
        temp->next=countTemp->next;
        countTemp->next=temp;
    }



}
void print(Node*&tail){
    Node*temp=tail;
    // simple loops not print 1 lement 
    // while(temp->next!=tail){
    //     cout<<temp->data<<" ";
    //     temp=temp->next; 

    // }
    do{
        cout<<tail->data<<" ";
        tail=tail->next;
    }while(tail!= temp);  
    cout<<endl;
    cout<<endl;

}

int main(){
    Node*node1=new Node(333);
    int arr[4]={1,2,3,4};
    Node*tail=fromArr(arr,4);
    print(tail);



}