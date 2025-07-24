#include<iostream>
// #include <bits/stdc++.h>
#include <map>
using namespace std;



// When you pass an array to a function like this:
// void printSize(char arr[]) {
//     cout << sizeof(arr) << endl;
// }
// It does not print the full size of the array.
//  Instead, it prints the size of a pointer, usually 4 bytes on 32-bit systems or 8 bytes on 64-bit systems.
//Even though strlen(arr) works fine, sizeof(arr) gives wrong result, because arr becomes a pointer in the function.
// C++ automatically converts (or "decays") arr into a pointer to the first element.
// So inside the function, arr is treated as a char*, not as a real array anymore.
// sizeof(arr) → means sizeof(char*) = 8 bytes on 64-bit, 4 bytes on 32-bit.
// It doesnt know how many elements are in the array, because it only has the address, not the actual array.


     



// q1
// brute  0(n2)// normal 2 loops 
// // optimal 


int maxProduct(vector<int>& nums) {
    // keep gettig product from 2 sides 
    // 2 cases when prodcut is 0;
    // whne product is negative 
    // if 2 negative then positoves if odd negaives then negative produvt
        int prefix=1;
        int suffix=1;
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(prefix==0){
                prefix=1;
            }
            if(suffix==0){
                suffix=1;
            }
            prefix=prefix*nums[i];
            suffix=suffix*nums[nums.size()-i-1];
            ans=max(ans,max(suffix,prefix));
            
            
        }
        return ans;


        
    }







// reverse pairs q2

//brute force --  2 loops o(n2)


// optimal nlogn
int count=0;



void check(vector<int>&nums,int s,int e,int mid){

    int right=mid+1;
    int left=s;
       int right=mid+1;
       vector<int>temp;
       while (left <= mid) {  //not writing right<e coz the right size not always same size as of the left side 
        while (right <= e && (long long)nums[left] > 2LL * nums[right]) {
            right++;
        }
        count += (right - (mid + 1));
        left++;  // Move `left` forward
       }
}
void merge(vector<int>&nums,int s,int e,int mid){
    vector<int>temp;
    int left=s;
    int right=mid+1;
    while(left<=mid && right<=e){
        if(nums[left]>nums[right]){
            temp.push_back(nums[right]);
            right++;

        }
        else{
            temp.push_back(nums[left]);
            left++;
        }
    }
    while(left<=mid){
        temp.push_back(nums[left]);
        left++;
    }

    while(right<=e){
        temp.push_back(nums[right]);
        right++;
    }
    for(int i=s;i<=e;i++){
        nums[i]=temp[i-s];
    }
}


void mergeSort(vector<int>&nums,int s,int e){
    if(s>=e){
        return;
    }
    int mid=s+(e-s)/2;
    mergeSort(nums,s,mid);
    mergeSort(nums,mid+1,e);
    check(nums,s,e,mid);

    merge(nums,s,e,mid);
    

}
  int reversePairs(vector<int>& nums) {
        int count=0;
        mergeSort(nums,0,nums.size()-1);
        return count;
        
}


//q4
// find missing and repeaitng
// brute cycle sort

// better using map

// find missing and repeating element
// brute o(n2)
// better hashing


vector<int> findTwoElement(vector<int>& arr) {
    int n=arr.size();
    
    
    int hash[n+1]={0};
    for(int i=0;i<n;i++){
        hash[arr[i]]++;
    }
    int repeating=-1;
    int missing=-1;
    for(int i=1;i<=n;i++){
        if(hash[i]==2){
             repeating=i;
        }
        if(hash[i]==0){
             missing=i;
        }
        if(repeating!=-1 && missing!=-1){
            break;
        }
    }
    return {repeating,missing};
}



   

// optimal approach// // maths
vector<int> findTwoElement(vector<int>& arr) {
    long long n=arr.size();
    long long SN=n*(n+1)/2;
    long long S2N=(n*(n+1)*(2*n+1))/6;
    long long s=0;
    long long s2=0;
    for(int i=0;i<n;i++){
        s+=arr[i];
        s2+=(long long )arr[i]*(long long )arr[i];
    }
    // x=repeating
    // y=missing 
    long long val1=s-SN;// x-y==val1
    long long val2=s2-S2N;// x2-y2=val2
    val2=val2/val1;// x+y==val2=val2/x-y
    long long x=(val1+val2)/2;//2x=val1+val2;
    long long y=x-val1;
    return{(int)x,(int)y};
}



// Q5 optimal approach consant spcae

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1;
        int j=n-1;
        int k=m+n-1;
        while(i>=0 && j>=0){
            if(nums1[i]>nums2[j]){
                nums1[k--]=nums1[i--];
            }
            else{
                nums1[k--]=nums2[j--];
            }
        }
        while(i>=0){
                nums1[k--]=nums1[i--];

        }
        
        while(j>=0){
                            nums1[k--]=nums2[j--];
 
            
        }
    }





// merge overlapping intervals  q6
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());// sorting the pairs

        int n=intervals.size();
        vector<vector<int>>ans;// to store the merged 

        for(int i=0;i<n;i++){
            if(ans.empty() ||  intervals[i][0]>ans.back()[1] ){// creating new intervl in pair is not overlapping  or fisr pair to be created
                ans.push_back(intervals[i]);
            }
            else{
                ans.back()[1]=max(ans.back()[1],intervals[i][1]);
            }
        }
        return ans;

        
    }
    long subarrayXor(vector<int> &arr, int k) {
        
        map<int,int>m;
        int count=0;
        int xr=0;
        m[xr]++;
        
        for(int i=0;i<arr.size();i++){
            xr=xr^arr[i];
            
            int remain=xr^k;
            count+=m[remain];
            m[xr]++;
            
            
        }
        // code her
        return count;
        
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        int n=nums.size();

        for(int i=0;i<n;i++){

            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
                        

            for(int j=i+1;j<n;j++){
                if(j!=i+1 && nums[j]==nums[j-1]){
                continue;
                }
                int k=j+1;
                int l=n-1;
                while(k<l){
                    long long sum=(long long)nums[i]+nums[j]+nums[k]+nums[l];
                if(sum>target){
                    l--;
                }
                else if(sum<target){
                    k++;

                }
                else{
                    vector<int>temp={nums[i],nums[j],nums[k],nums[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while(k<l && nums[k]==nums[k-1]){
                        k++;

                    }       
                    while(k<l && nums[l]==nums[l+1]){
                        l--;

                    }                
                }
                    
                }

            }
            


        }
        return ans;
        
    }




    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
      
        for(int i=0;i<n;i++){

            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum>0){
                    k--;
                }
                else if(sum<0){
                    j++;

                }
                else{
                    vector<int>temp={nums[i],nums[j],nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]){
                        j++;

                    }       
                    while(j<k && nums[k]==nums[k+1]){
                        k--;

                    }                
                }
                
            }
            
        }
        return ans;
        
    }

    // q11
    // majority elemnt 2
    // q10 majority elemnt 2

    // optimal soll
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        int count1=0;

        int count2=0;
        int curr1=INT_MIN;
        int curr2=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            
            if(count1==0 && curr2!=nums[i]){
                count1=1;
                curr1=nums[i];
            }
            else if(count2==0 && curr1!=nums[i] ){
                count2=1;
                curr2=nums[i];
            }
            else if(nums[i]==curr1){
                count1++;
            }
            else if(nums[i]==curr2){
                count2++;
            }
            else{
                count1--;

                count2--;
            }
        }
        int counts1=0;
        int counts2=0;

            for(int i=0;i<n;i++){
                if(nums[i]==curr1){
                    counts1++;
                }
                if(nums[i]==curr2){
                    counts2++;
                }
            }
            if(counts1>(n/3)){
                ans.push_back(curr1);
            }
            if (counts2 > n / 3 && curr1 != curr2){ // Avoid duplicates
                ans.push_back(curr2);
            }
            return ans;
    }
    // pASCAL TRIANGEL
    vector<vector<int>> generate(int numRows) {


        vector<vector<int>>ans;
        for(int i=0;i<numRows;i++){

        ans.push_back(vector<int>(i + 1, 1)); // Create a new row of size (i+1) filled with 1s
            for(int j=1;j<i;j++){
                ans[i][j]=ans[i-1][j]+ans[i-1][j-1];

            }
        }
        return ans;
        
    }



    int subarraySum(vector<int>& arr, int k) {
        map<int,int>hashmaps;// key-sum,value-index
    int sum=0;
    int l=0;
    int count=0;



    for(int i=0;i<arr.size();i++){
        sum=sum+arr[i];
        if(sum==k){
            count++;
        }
        int remain=sum-k;// we will find the index where th remain is in map as from there till current index that will be length
        if(hashmaps.find(remain)!=hashmaps.end()){
                count += hashmaps[remain];
                //reason below
// | Index | Sum | count// +=hashmpa | hashmaps\[sum]// value are hashmap |
// | ----- | --- | ----- | -------------- |
// | 0     | 0   | 1     | 1              |
// | 1     | 0   | 3     | 2              |
// | 2     | 0   | 6     | 3              |


        }
        // avoid duplicate elements  and 0's as thsi will decrese the length
        // if(hashmaps.find(sum)==hashmaps.end()){
            hashmaps[sum]++;

        

    }
    return count;     
    }


/// for neagtices positives and 0
int longestSubarray(vector<int>& arr, int k) {

    map<int,int>hashmaps;// key-sum,value-index
    int sum=0;
    int l=0;



    for(int i=0;i<arr.size();i++){
        sum=sum+arr[i];
        if(sum==k){
            l=max(i+1,l);
        }
        int remain=sum-k;// we will find the index where th remain is in map as from there till current index that will be length
        if(hashmaps.find(remain)!=hashmaps.end()){
            int newL=i-hashmaps[remain];
            l=max(l,newL);

        }
        // avoid duplicate elements  and 0's as thsi will decrese the length
        if(hashmaps.find(sum)==hashmaps.end()){
            hashmaps[sum]=i;

        }

    }
    return l;    
}
// 2 pointer approach with no negativses
int longestSubarrays(vector<int>& arr, int k) {

    int left=0;
    int right=0;
    int maxl=0;
    int n=arr.size();
    int sum=0;

    while(right<n){
        sum=sum+arr[right];

        while(left<=right && sum>k){
            sum=sum-arr[left];
            left++;
        }
        
        if(sum==k){
            maxl=max(maxl,right-left+1);
        }
        right++;




    }
    return maxl;

}




vector<int> rearrangeArray(vector<int>& nums) {

        vector<int>positive;
        vector<int>negative;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                positive.push_back(nums[i]);

            }
            else{
                negative.push_back(nums[i]);

            }
        }
        int n=positive.size();
        int m=negative.size();

        int s=nums.size();
            if(n>m){// postives are more
                for(int i=0;i<m;i++){// filling the feweer elemnts first 
                    nums[2*i]=positive[i];
                     nums[2*i+1]=negative[i];
                }
                int index=m*2;
                for(int i=m;i<n;i++){/// now filling the majority one //starting form where it ended at last 
                    nums[index]=positive[i];
                    index++;
                }

            }
            else{

                for(int i=0;i<n;i++){// filling the feweer elemnts first 
                    nums[2*i]=positive[i];
                     nums[2*i+1]=negative[i];
                }
                int index=n*2;
                for(int i=n;i<m;i++){/// now filling the majority one //starting form where it ended at last 
                    nums[index]=negative[i];
                    index++;
                }

            }


        return nums;
        

        
}

void setZeroes(vector<vector<int>>& matrix) {
    // marlkinh the 0th row and 0th col for chexckinh
    // int n=matrix.size();
    // int m=matrix[0].size();
    int col=1;// for the matrix[0][0] coz ine is used already by j=0 for marking
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            if(matrix[i][j]==0){


                matrix[i][0]=0;
                if(j!=0){
                    matrix[0][j]=0;
                }
                else{
                    col=0;
                }
            }
        }
    }
    for(int i=1;i<matrix.size();i++){
        for(int j=1;j<matrix[0].size();j++){
            if(matrix[i][j]!=0){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }

            }
            
        }
    }

    if(matrix[0][0]==0){
                    for(int j=0;j<matrix[0].size();j++){
                        matrix[0][j]=0;
                    }
    }
    if(col==0){
        for(int i=0;i<matrix.size();i++){
            matrix[i][0]=0;
        }

    }
    
}
void rotate(vector<vector<int>>& matrix) {
    int n=matrix.size();

    // transpsiong 

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j>i){
                int temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }

        }
    }
    for(auto&arr:matrix){
        reverse(arr.begin(),arr.end());
    }

    
}
vector<int> spiralOrder(vector<vector<int>>& matrix) {

    int n=matrix.size()-1;
    int m=matrix[0].size()-1;
    vector<int>ans;



    int top=0;
    int bottom=n;
    int left=0;
    int right=m;


    while(left<=right && top<=bottom){
        for(int i=left;i<=right;i++){
            ans.push_back(matrix[top][i]);
        }
        top++;

        for(int i=top;i<=bottom;i++){
            ans.push_back(matrix[i][right]);
        }
        right--;
        if(top<=bottom){
            for(int i=right;i>=left;i--){
            ans.push_back(matrix[bottom][i]);
            }
        bottom--;
        }
        if(left<=right){
            for(int i=bottom;i>=top;i--){
            ans.push_back(matrix[i][left]);
            }
        left++;
        }
        
    }
    return ans;
}
    


int longestConsecutive(vector<int>& nums) {
    int n=nums.size();
    if(n==0){
        return 0;
    }
    int ans=0;


    unordered_map<int,bool>m;

    for(int i=0;i<n;i++){
        m[nums[i]]=false;
    }

    for(int i:nums){
        int maxLen=0;
        int next=i+1;

        while(m.count(next) && m[next]==false){
            maxLen++;
            m[next]=true;
            next++;
        }
        int prev=i-1;

        while(m.count(prev) && m[prev]==false){
            maxLen++;
            m[prev]=true;
            prev--;
        }


        ans=max(ans,maxLen);
    }
    return ans+1;// or we can INITIALIZE maxLen with 1

    
} 
vector<int> leaders(vector<int>& arr) {
    // Code 
    vector<int>ans;
    
    int maxi=INT_MIN;
    for(int i=arr.size()-1;i>=0;i--){
        
        if(arr[i]>=maxi){
            ans.push_back(arr[i]);
        }
        maxi=max(maxi,arr[i]);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
// next permuatauion

// brute
// generate all permuatuions suing recusion then se linear search to find the og arraya nd then return the just next elemnt of array

// better 
// suing stl        next_permutation(nums.begin(),nums.end());

// optimal
void nextPermutation(vector<int>& nums) {
    int n=nums.size();
    // selectiig the peak so that elenmnt before it will alwasy be smaller and thats what we need to swpa to get just next permutauion
    int i=n-1;

    while(i>0 && nums[i]<=nums[i-1] ){
        i--;
    }
    // if sull stirng in in increaing just return the revese
    if(i==0){
        reverse(nums.begin(),nums.end());
        return;
    }

    int j=n-1;
    // moving j just before the peak elemnt 
    // finding j such taht it is jjust greater than i-1 which we have to replace
    while(j>=i && nums[j]<=nums[i-1]){
        j--;
    }
    // till now we woudl have find the  just greater
    swap(nums[j],nums[i-1]);
    reverse(nums.begin()+i,nums.end());


    
    
}
// kadanes
int maxSubArray(vector<int>& arr) {
        
    int n = arr.size();
     int sum = 0;
     int maxi = arr[0];  // Start with the first element

     for (int i = 0; i < n; i++) {
         sum += arr[i];
         maxi = max(maxi, sum);
         if (sum < 0) {
             sum = 0;
         }
     }
     return maxi;
}
// majorti 1
int majorityElement(vector<int>& nums) {
    int n=nums.size();

    
    int count=0;
    int i=0;
    int ch;
    while(i<n){
        if(count==0){
            ch=nums[i];
            count=1;

        }
        else if(nums[i]==ch){
            count++;
        }
        else{
            count--;
        }
        i++;
    }
   return ch;
    
}     
    

// app1 brute force nlogn// merge sort
// app2 move 0 to end approach by counting the 1 0 and 2'ws
// app3 optinal
// sort 0 ,1 ,2 optimal approch   tc 0(n)as n tims elemnt approcehd in arr  space =0(1)constatn
void sortColors(vector<int>& nums) {

    int ones=0;
    int zeroes=0;
    int twos=nums.size()-1;

    while(ones<=twos){
        if(nums[ones]==0){
            swap(nums[ones],nums[zeroes]);
            ones++;
            zeroes++;
        }
        else if(nums[ones]==1){
            ones++;
        }
        else{
            swap(nums[ones],nums[twos]);
            twos--;
        }
    }
    
}
//laregst in array

int largest(vector<int>hlo,int n){
    int largest=hlo[0];
    for(int i=1;i<n;i++){
        if(hlo[i]>largest){
            largest=hlo[i];
        }
    }
    return largest;

}



// second largest 
int largest2nd(vector<int>hlo,int n){
    int largest=hlo[0];
    int largest2=-1;
    for(int i=1;i<n;i++){
        if(hlo[i]>largest){
            largest2=largest;
            largest=hlo[i];
        }
        else if(hlo[i]<largest && hlo[i]>largest2){
            largest2=hlo[i];
        }




    }
    return largest2;



}

// remove duplicates from an array

int removeDuplicates(vector<int>& nums) {

    int i=0;
    for(int j=1;j<nums.size();j++){
        if(nums[i]!=nums[j]){
            nums[i+1]=nums[j];// sothat wehen there are consicutive similar elents i not updatse and we can update the value  
            i++;

        }
    }
    return i+1;
     
        
}

void reverse(vector<int>& nums,int start,int end){
    while(start<end){
        int temp=nums[start];
        nums[start]=nums[end];
        nums[end]=temp;
        start++;
        end--;


    }
}
void rotate(vector<int>& nums, int k) {
    int n=nums.size();
        k = k % n;  // Adjust k if it's larger than the array size


    reverse(nums,0,n-k-1);
    reverse(nums,n-k,n-1);
    reverse(nums,0,n-1);




    
        
}


//move zeroes to END

void moveZeroes(vector<int>& nums) {

    vector<int>temp;

    for(int i=0;i<nums.size();i++){
        if( nums[i]!=0){
            temp.push_back(nums[i]);
        }
    }
    int n=temp.size();
     for(int i=0;i<n;i++){
        nums[i]=temp[i];
    }
     for(int i=n;i<nums.size();i++){
            nums[i]=0;

    }

        
}

// searchng
bool Lsearch(int arr[],int key,int n){

    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return true;
        }
       
    }
    return false;

}
int Lsearch1(int arr[],int key,int n){

    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return i;
        }
       
    }  
    return -1;

}
int bsearch(int arr[],int key,int n){
    int start=0;
    int end=n-1;
    int mid=(start+end)/2;
    for(int i=0;i<n;i++){
        if(arr[mid]>key){
            end=mid;
        }
        else if(arr[mid]<key){
            start=mid;
        }
        else{
            return mid;
        }
        mid=(start+end)/2;


    }
    return -1;
    
}




vector<int> unions(int arr1[],int arr2[],int n,int m){
    vector<int>temp;
    int i=0;
    int j=0;
        int k = m + n - 1;  // Last index of the merged array (arr)

    while( i<n &&  j<m){
        if(arr1[i]>arr2[j]){
            arr1[k] = arr1[i];
            i--;
        }
        else if(arr1[i]<arr2[j]){
            arr1[k] = arr2[i];
            j--;
            
        }
        
    }
    while( i<n ){
         temp.push_back(arr1[i]);
        i++;
    }
    while (j < m) {
        temp.push_back(arr2[j]);
        j++;
    }

    return temp;
    


}
// find misssing 

int missingNumber(vector<int>& nums) {
    int n = nums.size();

    // Cycle Sort
    // for (int i = 0; i < n; i++) {
    //     // Place nums[i] in the correct index nums[i] - 1 (if nums[i] is in the valid range)
    //     while (nums[i] >= 0 && nums[i] < n && nums[i] != nums[nums[i]]) {
    //         // Swap the current element with the element at the correct position
    //         swap(nums[i], nums[nums[i]]);
            
    //     }
    // }
    sort(nums.begin(),nums.end());

    // Find the first missing number
    for (int i = 0; i < n; i++) {
        if (nums[i] != i) {
            return i;  // First missing positive integer
        }
    }

    // If no missing element in the sequence, return n
    return n;
}


// apparn once other twice


















//   2D ARRAY

// muiltplaction

vector<vector<int>> mupliply(vector<vector<int>>vt2d1,int r1,int c1,vector<vector<int>>vt2d2,int r2,int c2){
    // vt1 col and vt2 rows must be same 
    //  c1=r2
    vector<vector<int>>prdt(r1,vector<int>(c2));

  
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            for(int k=0;k<r2;k++){
                prdt[i][j]=vt2d1[i][k]*vt2d2[k][j];

            }
        }
    }
    return prdt;

}

// wave transvrsal

void wave(vector<vector<int>>vt,int r,int c){


        for(int j=0;j<c;j++){
            if(j%2==0){
                for(int i=0;i<r;i++){
                    cout<<vt[i][j]<<endl;

                }

            }
            else{
                for(int i=r-1;i>=0;i--){
                    cout<<vt[i][j]<<endl;


                } 

            }
           
        }
    
}










int main(){

}