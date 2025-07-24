
#include<iostream>
using namespace std;
// using array with currSize


// WITH ARRAY
class Node{
    public:
    int data;
    Node*next;
    Node(int data){ 
        this->data=data;
        this->next=NULL;
    }

};
class Queue{
    public:
    int front;//to alwas pop at the start
    int rear;// to add end at end pointers
    int  size;
    int *arr;
    int currSize;
    Queue(int size){
        this->size=size;
        arr=new int[size];
        front=0;
        rear=-1;
        currSize=0;
     
    }
    void push(int data){
        if(size==currSize){
            cout << "Queue is full!" << endl;
            return;
        }
        rear = (rear + 1) % size; // Circular increment

        arr[rear]=data;
        currSize++;
    }
    int  pop(){
        if(currSize==0){
            cout << "Queue is empty!" << endl;
            return -1;
        }


        front = (front + 1) % size; // Circular increment

        int removed = arr[front];
        currSize--;
        return removed;

    }
};

// not using currSize
class MyQueue {
private:
    int arr[100005];
    int front;
    int rear;

public :
    MyQueue(){front=0;rear=0;}
    void push(int);
    int pop();

    void MyQueue ::push(int x) {
    
if ((rear + 1) % 100005 == front) { 
        // Queue is full (circular condition)
        return;
    }
    arr[rear]=x;
    rear = (rear + 1) % 100005; // Circular increment

    // Your Code
}

// Function to pop an element from queue and return that element.
int MyQueue ::pop() {
    if(front==rear){
        return -1;
    }
    int ele=arr[front];
            front = (front + 1) % 100005; // Circular increment

    return ele;
    // Your Code
}
};
 

// Function to push an element x in a queue.

// USING LINKEDLIST

class QueueLL{

    Node*front;
    Node*rear;
    QueueLL(){
        front==NULL;
        rear=NULL;
    }
    void push(int data){
        Node*temp=new Node(data);
        if(rear==nullptr){
            temp=rear=front;
            return;
        }
        rear->next=temp;
        rear=temp;

    }
    int pop(){
        if(front==NULL){
            cout<<"underflow"<<endl;
                        return -1;

        }
        Node*temp=front;
                int removedValue = temp->data;
                if (front == nullptr) { // If queue becomes empty, reset rear too
            rear = nullptr;
        }

        front=front->next;
        delete temp;
                return removedValue;

    }

};

// using a stack
class MyQueue {

    stack<int>s1,s2;


    MyQueue(){
    }

    void push(int data){
        s1.push(data);
    }

    int pop(){
        if(s2.empty()){
            while(!s1.empty()){
                int ele=s1.top();
                s2.push(ele);
                s1.pop();
            }
        
        }
        int ans=s2.top();
        s2.pop();
        return ans;
        
    }
    int peek(){
        if(s2.empty()){
            while(!s1.empty()){
                int ele=s1.top();
                s2.push(ele);
                s1.pop();
            }
        
        }
        int ans=s2.top();
        return ans;
        
    }
    bool empty() {
        return s1.empty() && s2.empty();
    }

};



int main(){

} 