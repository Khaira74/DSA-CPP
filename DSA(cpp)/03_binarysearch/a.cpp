#include<iostream>
using namespace std;






  int findPeakElement(vector<int>& arr) {
        if(arr.size()==1){
            return 0;
        }
        int s=0;
        int e=arr.size()-1;
        if(arr[0]>arr[1]){
            return 0;
        }
        if(arr[e]>arr[e-1]){
            return e;
        }
        int newS=1;
        int newE=e-1;
         while(newS<=newE){
            int mid=(newS+newE)/2;
            if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1]){
                return  mid;

            }
            else if (arr[mid]<arr[mid+1]){
                newS=mid+1;

            }
            else{
                newE=mid-1;
            }
    
         }
         return -1;
        
    }
// find peak elemnt 2


    int maxCol(vector<vector<int>>& mat,int n,int mid) {
        int maxVal=mat[0][mid];
        int index=0;
        for(int i=0;i<n;i++){
            int ele=mat[i][mid];
            if(ele>maxVal){
                maxVal=ele;
                index=i;

            }

        }
        return index;

    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        int n=mat.size();
        int m=mat[0].size();
        int start=0;
        int end=m-1;
        while(start<=end){
            int mid=(start+end)/2;
            int max=maxCol(mat,n,mid);
            
            int left = -1;  // Initialize left neighbor to -1
            if (mid - 1 >= 0) {
              left = mat[max][mid - 1]; // Set to the left neighbor if it exists
            }

           int right = -1; // Initialize right neighbor to -1
           if (mid + 1 < m) {
              right = mat[max][mid + 1]; // Set to the right neighbor if it exists
            }
            if(mat[max][mid]>left && mat[max][mid]>right){
                return {max,mid};

            }
            else if(left>mat[max][mid]){
                 end=mid-1;

            }
            else{
                start=mid+1;
            }

        } 
        return{-1,-1};
        
        
    }



    int count1s(vector<int> &arr,int m) {
        
         int index=arr.size();// so that is cancels m and countbecomes 0
            int start=0;
            int end=m-1;
            while(start<=end){
                int mid=(start+end)/2;
                if(arr[mid] >=1){
                    index=mid;
                    
                    end=mid-1;
                    
                }
                else{
                    start=mid+1;
                }
                
            }
        return index;
        
    }

    int rowWithMax1s(vector<vector<int>> &arr) {
        int result=-1;
        int rowNo=-1;
        
        
        int n=arr.size();
        int m=arr[0].size();
        for(int i=0;i<n;i++){
            int count=m-count1s(arr[i],m);
            if(count>result){
                result=count;
                rowNo=i;
            }
           
        }
        return rowNo;
        // code here
    }








    //medain of 2 sorted arrays

    // brute using constacnt space o(n)

    // better  not usinng constant space inbuilt only
    


    // if even size than s+e/2
    // if odd than s+e/2



     bool possible(vector<int>& arr, int n, int m,int mid) {
        int studentCount=1;
        int sum=0;
        for(int i=0;i<n;i++){
            if(arr[i]+sum<=mid){// just before calacualting the sum value;
                sum+=arr[i];
            }
            else{
                studentCount++;//counter indcreases
                if(studentCount>m || arr[i]>mid){
                    return false;
                }
                                sum=arr[i];// new sum starteda agaain

            }

        }
        return true;
    }

     int findPages(vector<int>& arr, int n, int m) {
        // Write your code here.
        if (m > n) return -1;
     
       
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        int s=0;
        int e=sum;
        int mid=s+(e-s)/2;
        int ans=0;
        while(s<=e){
            if(possible(arr,n,m,mid)){
                ans=mid;
                e=mid-1;//for ganjash not settling till we find the exact smallest sum untill s>e
            }
            else{
                s=mid+1;// if mid value if smaller
            }
            mid=s+(e-s)/2;
        }
        return ans;

    }
    
int main(){

}