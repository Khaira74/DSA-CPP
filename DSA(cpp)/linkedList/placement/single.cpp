#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int data,Node*next){
        this->data=data;
        this->next=next;

    }
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
    
};
Node* converttoLL(vector<int>&arr){
    int n=arr.size();
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<n;i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;


}
void print(Node*&head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next; 

    }

}
void insertHead(Node*&head,int data){
     Node*temp=new Node(data);
     temp->next=head;
     head=temp;

}
void insertTail(Node*&tail1,int data){
    Node*temp=new Node(data);
    tail1->next=temp;
    tail1=temp;

}
void insertMiddle(Node*&head,int data,int pos){
    int count=0;
    Node*counttemp=head;
        while(count<pos-1){
            counttemp=counttemp->next;
            count++;
    }
    Node*temp=new Node(data);
    temp->next=counttemp->next;
    counttemp->next=temp;
}
void deleteted(Node*&head,int pos){
    if(pos==1){
        Node*temp=head;
        head=head->next;
        temp->next=nullptr;
        delete temp;
    }
    else{
        Node*curr=head;
        Node*prev=NULL;
        int count=1;
        while(curr != nullptr && count<pos){// if count is 
            prev=curr;
            curr=curr->next;
            count++;
        }
        if (curr == nullptr) {
            cout << "Position exceeds list length." << endl;
            return;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }

}




int main(){
    cout<<"enter the size "<<endl;

    int size;
    cin>>size;
    int arr[size];
    cout<<"inserting array // creating the array"<<endl;

    for(int i=0;i<size;i++){
        cin>>arr[i];
    }

    Node t1=Node(arr[0],nullptr);
    Node *t2=new Node(arr[0],nullptr);
        cout<<"creat a node or object and printing its next"<<endl;

    cout<<t1.next;
            cout<<"creat a node or object and printing its next"<<endl;

     cout<<t2->next;

     // creating using array
    cout<<"creat a LL using a array or vector "<<endl;

    cout<<"enter the size"<<endl;
     int n;
     cin>>n;
     vector<int>v(n);
    cout<<"enter the vector or array"<<endl;

    for(int i=0;i<size;i++){
        cin>>v[i];
    }

    Node* head=converttoLL(v);//
            cout<<"printitgn the linlked list we created using  a veecotr or array"<<endl;

    print(head);// printing 

    // inserting 


    Node* node1=new Node(22);
    Node*head1=node1;
    Node*tail1=node1;
    // inserting at head
    cout<<"inserting at head to new linked list with using a head"<<endl;
    insertHead(head1,21);
        insertHead(head1,20);
    insertHead(head1,19);

        cout<<"printing at head"<<endl;

    print(head1);
   



    //inseet at tail


    cout<<"inserting at tail to new linked list with using a head"<<endl;
    insertTail(tail1,55);
    print(head1);

    // insert at middle
    cout<<"inserting inmiddle"<<endl;
    insertMiddle(head1,555,4);
    print(head1);

    


}