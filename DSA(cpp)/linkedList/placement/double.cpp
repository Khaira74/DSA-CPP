#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next;
    Node*prev;
    Node(int data,Node*next,Node*prev){
        this->data=data;
        this->next=next;
        this->prev=prev;
    }
    Node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
};



Node* arrayToLL(vector<int>arr){
    if (arr.empty()) return nullptr; // Handle empty array case

    Node*head=new Node(arr[0]);
    Node*mover=head;
    for(int i=1;i<arr.size();i++){
        Node*temp=new Node(arr[i]);
        mover->next=temp;
        temp->prev=mover;
        mover=temp;

    }
    return head;
}

void deleteHead(Node*head){
    if(head==NULL){
        return;
    }
    Node*temp=head;
    head=head->next;
    head->prev=NULL;
    temp->next=NULL;
    delete head;
}
void deletetail(Node*head){
    Node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }

    Node*back=temp->prev;
    back->next=NULL;
    temp->prev=NULL;
    delete temp;

}
void deleteKth(Node*head,int k){
    if(head==NULL || head->next==NULL){
        return;
    }
    if(k==1){
        deleteHead(head);
        return;
    }
    else{

    int count=1;
    Node*curr=head;
    Node*back=NULL;
    while(curr!=NULL && count<k){
        back=curr;
        curr=curr->next;
        count++;
    }
    if(curr==NULL){
        return;
    }
    if(curr->next==NULL){// tail
        deletetail(head);
        return;

    }
    back->next=curr->next;
    curr->next->prev=back;

    curr->next=NULL;
    curr->prev==NULL;
    delete curr;

    }
}

void print(Node*head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int length(Node*head){
    Node*temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}

void insertHead(Node*&head,int data){
    if(head==NULL){
        Node*temp=new Node(data);
        head=temp;
    }
    else{
         Node*temp=new Node(data);
    temp->next=head;
    head->prev=temp;
    head=temp;

    }
   

}
void insertTail(Node*&tail,int data){
    if (tail==NULL){
        Node*temp=new Node(data);
        tail=temp;
        
        /* code */
    }
    
    Node*temp=new Node(data);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;

}

void inserting(Node*&head,int data,int pos){
    if(pos==1){
        insertHead(head,data);
    }
    else{
        int count=1;
        Node*temp=head;
        while(count<pos-1 && temp != nullptr){
            count++;
            temp=temp->next;
        }
        if(temp==NULL){
            return;
        }
        Node*toInsert=new Node(data);
        toInsert->next=temp->next;

        if(temp->next!=NULL){//  not tail
        temp->next->prev=toInsert;

        }
        temp->next=toInsert;
        toInsert->prev=temp;
        
        
        
    }
}
void insertMiddle(Node*&head,int data,int pos){

    if(pos==1){
         insertHead(head,data);
         return;
    }
    else{
        int count=1;
        Node*CountTemp=head;// counter node
        while(count<pos-1){
            CountTemp=CountTemp->next;
            count++;

        }
        if(CountTemp->next==NULL){
        insertTail(head,data);
        return;
        }
        Node*temp=new Node(data);// node to be inserted
        temp->next=CountTemp->next;
        temp->prev=CountTemp;
        CountTemp->next->prev=temp;
        CountTemp->next=temp;
    }

}





int main(){
    int n;
    cin>>n;
    Node* node1=new Node(n);
    Node*head1=node1;
    print(head1);

    Node*empty=NULL;

    print(empty);    
    Node*head=empty;
    insertHead(head,44);

    insertHead(head,45);
    insertHead(head,46);
    insertHead(head,47);
    insertHead(head,48);
    insertHead(head,49);

    print(head);    
}