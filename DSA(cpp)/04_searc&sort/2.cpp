// sorting
#include<iostream>
using namespace std;



// selection sort 
// https://www.geeksforgeeks.org/problems/selection-sort/1
// here we sort every element seprately till the array is fully sorted 
// smallest element first sorted 



void selectionSort(vector<int> &arr) {
        int n=arr.size();
        
        for(int i=0;i<n;i++){
            int minindex=i;
            
            for(int j=i+1;j<n;j++){
                if(arr[minindex]>arr[j]){
                    minindex=j;
                }
                
            }
            
            swap(arr[i],arr[minindex]);// arr[i] is the palce where smallest elemnt will come
            
        }
        // code here
        
}






// bubble sort
// https://www.geeksforgeeks.org/problems/bubble-sort/1
// neumoinic bubbles are round
// here ke keep swappinh the elemeny with next greater elemts   using rounds sysem
void bubbleSort(vector<int>& arr) {
        
        int n=arr.size();
        
        
        
        for(int i=1;i<n;i++){
            for(int j=0;j<n-i;j++){
                if(arr[j]>arr[j+1]){
                    swap(arr[j],arr[j+1]);
                }
            }
        }
        
    }

// insertion sort
// herer we comapre withn the prevois element and thne keep moving back till starting elemnt and then change the postion with it 

void  insertion(int arr[],int n){
    for(int i=1;i<n;i++){
        int temp=arr[i];
        int j=i-1;
        for(;j>=0;j--){
            if(temp<arr[j]){
                arr[j+1]=arr[j];// shifting continously till temp reaches corect place

            }
            else{
                break;// next value of i now
            }
        }
        // as we now standing at j th value where temp>arr[j] coz we breaked out at that j value 
        //as j+1 value is emepty as we have shofted them one point forward
        arr[j+1]=temp;
    }
}

void merge(vector<int>& nums,int s,int mid,int e) {
        vector<int>temp;
        int i=s;
        int j=mid+1;

        while(i<=mid && j<=e){
            if(nums[i]>=nums[j]){
                temp.push_back(nums[j]);
                j++;
            }
            else{
                temp.push_back(nums[i]);
                i++;
            }
        }
        while(i<=mid){
            temp.push_back(nums[i]);
             i++;

        }
         while(j<=e){
            temp.push_back(nums[j]);
             j++;

        }
        for (int k = 0; k < temp.size(); ++k) {
            nums[s + k] = temp[k];
        }
    }


    void mergeSort(vector<int>& nums,int s,int e) {

        if(s>=e){
            return;
        }
        int mid=(s+e)/2;

        mergeSort(nums,s,mid);
        mergeSort(nums,mid+1,e);
        merge(nums,s,mid,e);

    }

    vector<int> sortArray(vector<int>& nums) {


        mergeSort(nums,0,nums.size()-1);
        return nums;
        
    }
    int partition(vector<int>&arr,int s,int e){
        int pivot=arr[s];
        int count=0;
        for(int i=s+1;i<=e;i++){
            if(arr[i]<=pivot){
                count++;
            }
        }
        int pivotIndex=s+count;
        swap(arr[count],arr[pivotIndex]);
        int i=s;
        int j=e;
        while(i<pivotIndex && j>pivotIndex){
            if(arr[i]<pivot){
                i++;
            }
            if(arr[j]>pivot){
                j++;
            }
            if(arr[i]<pivot && arr[j]<pivot ){
                swap(arr[i],arr[j]);
            }
        }
        return pivotIndex;


    }
    void quick(vector<int>&arr,int s,int e){
        if(s==e){
            return;
        }

        int pivot=partition(arr,s,e);

        quick(arr,s,pivot-1);
        quick(arr,pivot+1,e);


    }
    void quickSort(vector<int>&arr){
        int s=0;
        int e=arr.size()-1;
        quick(arr,s,e);


        
    }


    


int main(){
    int arr[6]={7,9,4,0,2,6};
    int n=6;

    // selectionSort(arr);
    for(int i=1;i<n;i++){
        cout<<arr[i]<<endl;;
    }



}