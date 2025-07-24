#include<iostream>
using namespace std;


class Stack{
    public:
    int top;
    int size;
     int*arr;
    Stack(int size){
        size=size;
        arr=new int[size];
        top=-1;

    }
    void push(int data){
        if(size-top<=1){
            cout<<"over floww"<<endl;
            return;   

        }
        arr[++top]=data;// coz we need to increse the top value before putting elent to that index


    }
    void pop(){
        if(top<0){
            cout<<"stack uderflow"<<endl;
               return;

        }
        arr[top--];// we will remove by givig a delusion to array by decresing the top value coz there is not any way to delete an array elemnt
    }
    int peek() {
        if (top < 0) {
            cout << "Stack is empty\n";  
            return -1;
        }
        return arr[top];
    }
    void display() {
        if (top < 0) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }

};
class Node{
    public:
    int data;
    Node*next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
class StackLL{
    public:
    Node*top;
    StackLL(){
        top=NULL;
    }
    
    void push(int data){
        Node*temp=new Node(data);
        temp->next=top;
        top=temp;

    }
    void pop(){

        if(top==NULL){
            
            cout<<"underflow"<<endl;

        }
        Node* temp = top;
        top = top->next;
        cout << temp->data << " popped from stack\n";
        delete temp;



    }


};
class MyStack {
        queue<int>q;

public:
    MyStack() {
        
    }
    
    void push(int data){
        int s=q.size();
        q.push(data);
        for(int i=1;i<s;i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
                if (q.empty()) return -1;

        int elemnt=q.front();
        q.pop();
        
        return elemnt;
    }
    
    int top() {
                if (q.empty()) return -1;

        return q.front();
        
    }
    
    bool empty() {
        return q.empty();
        
    }
};





// string preToPost(string pre_exp) {
        
        
    //          stack<string>s;
    //         int n=pre_exp.length();
    //         int i=0;
    //         while(i<n){
    //             if(pre_exp[i]>='A' && pre_exp[i]<='Z' || pre_exp[i]>='a' && pre_exp[i]<='z'
    //             || pre_exp[i]>='0' && pre_exp[i]<='9'){
    //                  s.push(string(1,pre_exp[i]));
    //             }
    //             else{
    //                 if (s.size() < 2) return "Invalid Expression"; // Edge case: Not enough operands
    
    //                 string top1=s.top();
    //                 s.pop();
    //                 string top2=s.top();
    //                 s.pop();
    //                 string chs="("+top2+pre_exp[i]+top1+")";
    //                 s.push(chs);
                
    //             }
    //             i++;
    //         }
    //         return s.top();
    //         // Write your code here
    //     }



int main(){

    Stack ss(66);
    StackLL sp;
    MyStack sp;

}