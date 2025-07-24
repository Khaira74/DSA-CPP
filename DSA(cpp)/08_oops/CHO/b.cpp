#include<iostream>
using namespace std;


class ArraySorter{
    public:
    int n;
    int arr[100];

    ArraySorter(int n, int* inputArr) {
        this->n = n;
        for (int i = 0; i < n; ++i) {
            arr[i] = inputArr[i];
        }
    }
    ~ArraySorter() {
        // No dynamic memory to free
    }

    void sortArray(){
        
    }


};

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }


}