#include<iostream>
using namespace std;

class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

DLLNode* reverseDLL(DLLNode* head) { 
        stack<DLLNode*>s;
        DLLNode*temp=head;
        while(temp){
            s.push(temp);
            temp=temp->next;
        }
        head=s.top();
        s.pop();
        temp=head;
        
        while(!s.empty()){
            temp->next=s.top();
            s.top()->prev=temp;
            temp=s.top();
            s.pop();
            
        }
        temp->next = nullptr;

        return head;  
          
}



int main(){

}