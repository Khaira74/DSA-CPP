// linear search// basic search
#include<iostream>
using namespace std;



bool linear(int arr[],int k,int n){
    for (int i = 0; i < n; i++){
        if(arr[i]==k){
            return true;
        }
        else{
            return false;
        }
        
    }
    

}
// binary search// only work with either ascending or descending order  
// herer we use mid end start
int binary(int arr[],int n,int k){
    int s=0;
    int e=n-1;
    int m=(s+e)/2;
    for (int i = 0; i < n; i++){
        if(arr[m]==k){
            return m;// returns index
        }
        if(k<arr[m]){
            e=m-1;
        }
        else{
            s=m+1;
        }
        m=(s+e)/2;
    }
    return -1;


}
// find first and last occuring of an element  using   bs
// at what index did we find that elements 

int first(int arr[],int n,int k){
    int s=0;
    int e=n-1;
    int m=(s+e)/2;
    int ans=-1;
    for (int i = 0; i < n; i++){
        if(arr[m]==k){
            ans=m;
            e=m-1;
        }
        if(k<arr[m]){
            e=m-1;
        }
        else{
            s=m+1;
        }
        m=(s+e)/2;
    }
    return -1;


}



int last(int arr[],int n,int k){
    int s=0;
    int e=n-1;
    int m=(s+e)/2;
    int ans=-1;
    for (int i = 0; i < n; i++){
        if(arr[m]==k){
            ans=m;
            s=m+1;

            
        }
        if(k<arr[m]){
            e=m-1;
        }
        else{
            s=m+1;
        }
        m=(s+e)/2;
    }
    return -1;


}



