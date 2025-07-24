
#include<iostream>
using namespace std;


void selection(int arr[],int n){
    for(int i=0;i<n;i++){
                    int min=i;

        for(int j=i+1;j<n;j++){
            if(arr[min]>arr[j]){
                min=j;
            }

        }
        swap(arr[min],arr[i]);
    }

}
void bubble(int arr[],int n){
    for(int i=1;i<n;i++){

        for(int j=0;j<n-i;j++){//to zvoid j+1 out of bounds
            if(arr[j]<arr[j+1]){
                swap(arr[j],arr[j+1]);
            }

        }
       
    }
}


void arraymerge(int arr[],int n,int s,int e,int mid){
    vector<int>temp;
    int i=s;
    int j=mid+1;
    while(i<mid && j<e){
        if(arr[i]>arr[j]){
            temp.push_back(arr[j]);
            j++;

        }
        else{
            temp.push_back(arr[i]);
            i++;

        }
    }
    while(i<=mid){
          temp.push_back(arr[i]);
              i++;
          
      }
      while(j<=e){
          temp.push_back(arr[j]);
              j++;
          
      }



}
void merge(int arr[],int n,int s,int e){
    if(s>e){
        return;
    }
    int mid=s+e/2;
    merge(arr,n,s,mid);
    merge(arr,n,mid+1,e);
    arraymerge(arr,n,s,e,mid);
}
// quick sort

int partss(int arr[],int s,int e){
    int pivot=arr[s];
    int count=0;
    for(int i=s+1;i<e;i++){
        if(arr[i]>pivot){
            count++;
        }
    }
    swap(pivot,arr[count+s]);
    int pivotindex=s+count;
    int i=s;
    int j=e;
    while(i<pivot && j>pivot){
        while(arr[i]>arr[pivotindex]){
            i++;

        }
        while(arr[j]<arr[pivotindex]){
            j--;

        }
        if(i< pivotindex && j>pivotindex){
            swap(arr[i++],arr[j--]);
        }


    }

}
void quick(int arr[],int n,int s,int e){
    if(s>=e){
        return;
    }
    int pivot=partss(arr,s,e);

    quick(arr,n,s,pivot-1);

    quick(arr,n,pivot+1,e);
     
}
int main(){

    // 1d array

    int n;
    cout<<"enter the arr size"<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    //1d vector

    vector<int>v(n);

    cout<<"enter the vector"<<endl;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0;i<n;i++){
        cout<<v[i];
    }
    cout<<endl;


    // 2d array
    cout<<"enter the row"<<endl;

    int row;
    int col;
    cin>>row;

    cout<<"enter the col"<<endl;

    cin>>col;
    int arr2d[row][col];

    cout<<"enter the matrix"<<endl;

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>arr2d[row][col];
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<arr2d[row][col];
        }
        cout<<endl;
    }
    vector<vector<int>>v2d(row,vector<int>(col));


}
