#include<iostream>


using namespace std;



class Node{
    public:

    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->left=NULL;
        this->right=NULL;

        this->data=data;
    }


};
Node* create(Node*root){
    
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    root=new Node(data);


    root->left=create(root->left);
    root->right=create(root->right);
    return root;



    
}
void printTree(Node* root, int space = 0, int indent = 5) {
    if (root == NULL) return;

    // Increase distance between levels
    space += indent;

    // Print right child first
    printTree(root->right, space);

    // Print current node
    cout << endl;
    for (int i = indent; i < space; i++) cout << " ";
    cout << root->data << endl;

    // Print left child
    printTree(root->left, space);
}

Node*fromLO(Node*root){
    int data;
    cin>>data;
    if (data == -1) return NULL;
    root=new Node(data);
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node*temp=q.front();
        q.pop();
        int left;
        cin>>left;
        if(left!=-1){
            temp->left=new Node(left);
            q.push(temp->left);
        }        
        int right;
        cin>>right;

        if(right!=-1){
                temp->right=new Node(right);
                q.push(temp->right);
        }
    }
    return root;

}
//

int main(){


    Node*head1=NULL;
    head1=fromLO(head1);
    printTree(head1);

}