#include<iostream>
using namespace std;

//q4
class Node {
    public:
        int val;
        Node* next;
        Node* random;
        
        Node(int _val) {
            val = _val;
            next = NULL;
            random = NULL;
        }
};
void insertTail(Node*&cloneHead,Node*&cloneTail,int d){
    Node*newNode=new Node(d);
    if(cloneHead==NULL){
        cloneHead=newNode;
        cloneTail=newNode;

    }
    else{
        cloneTail->next=newNode;
        cloneTail=newNode;
    }
}

Node* copyRandomList(Node* head) {


    Node*cloneHead=NULL;
    Node*cloneTail=NULL;
    Node*temp=head;
    // creating the clone
    while(temp!=NULL){
        insertTail(cloneHead,cloneTail,temp->val);
        temp=temp->next;
    }

    // creating the map and adding in them

    unordered_map<Node*,Node*>m;
    Node*OGnode=head;
   Node*clonenode=cloneHead;



    while(OGnode!=NULL && clonenode!=NULL){

        m[OGnode]=clonenode;
        OGnode=OGnode->next;
        clonenode=clonenode->next;
    }
    OGnode=head;
    clonenode=cloneHead;
    // both will move simulatenoesly in below loop
    while(OGnode!=NULL){
        clonenode->random=m[OGnode->random];
        OGnode=OGnode->next;
        clonenode=clonenode->next;
        
    }
    return cloneHead;

}
//{ Driver Code Starts

struct Node {
    int data;
    struct Node* next;
    struct Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->bottom;
    }
    printf("\n");
}

Node* createLinkedList(vector<Node*>& v) {
    Node* head = new Node(0);
    Node* temp = head;
    int n = v.size();
    for (int i = 0; i < n; i++) {
        temp->next = v[i];
        temp = temp->next;
    }
    return head->next;
}


// } Driver Code Ends

/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
        Node* merge(Node*root1,Node*root2){
            if (!root1) return root2;
            if (!root2) return root1;
            Node*dummy=new Node(-1);
            Node*res=dummy;
            while(root1!=NULL && root2!=NULL ){
                if(root1->data < root2->data){
                    res->bottom=root1;
                    res=root1;
                    root1=root1->bottom;

                }
                else{
                    res->bottom=root2;
                    res=root2;
                    root2=root2->bottom;
                    
                }
            }
            if(root1){
                res->bottom=root1;
            }
            else{
                res->bottom=root2;

            }
           
            return dummy->bottom;
        }

    
   
    Node *flatten(Node *root) {
        if(root==NULL || root->next==NULL){
            return root;
        }
        
        Node*ans=flatten(root->next);
        return merge(root,root->next);
        
        
        // Your code here
    }
};





int main(){

}