#include<iostream>
using namespace std;
#include<set>

int findKthLargest(vector<int>& nums, int k) {

    priority_queue<int, vector<int>, greater<int>> minheap;
    for(int num:nums){
        minheap.push(num);
        if(minheap.size()>k){
            minheap.pop();
        }
    }
    return minheap.top();
    
}
int kthSmallest(vector<int> &arr, int k) {
    // code here
    
     priority_queue<int> minheap;
    for(int num:arr){
        minheap.push(num);
        if(minheap.size()>k){
            minheap.pop();
        }
    }
    return minheap.top();
    
}
void nearlySorted(vector<int>& arr, int k) {
        
    priority_queue<int,vector<int>,greater<int >>minheap;
    
    // loop runed till k as the first lement can be atmost
    //k index away from present index
    for(int i=0;i<=k &&i<arr.size();i++){
        minheap.push(arr[i]);// till ow fisrt k lements will have been  filled
        // in the heap with one elemnt more
    }
    
    int index=0;
    // now removing the  extra elemnt from heap for sorting the first element
    for(int i=k+1;i<arr.size();i++){
        arr[index++]=minheap.top();
        minheap.pop();
        minheap.push(arr[i]);
        
    }
    while(!minheap.empty()){
        arr[index++]=minheap.top();
        minheap.pop();
        
    }
    

    
    
    // code
}
vector<int> findClosestElements(vector<int>& arr, int k, int x) {

    auto compa=[x](int a,int b){
        int diffA=abs(a-x);
        int diffB=abs(b-x);
        if(diffA==diffB){
            return a<b;
        }
        return diffA<diffB;
    };

    priority_queue<int,vector<int>,decltype(compa)>maxheap(compa);

    for(auto i:arr){
        maxheap.push(i);
        if(maxheap.size()>k){
            maxheap.pop();
        }
    }

    vector<int>ans;
    while(!maxheap.empty()){
        ans.push_back(maxheap.top());
        maxheap.pop();
    }
    sort(ans.begin(),ans.end());
    return ans;
    
}
vector<int> topKFrequent(vector<int>& nums, int k) {
    int n=nums.size();

    unordered_map<int,int>m;
    for(int i=0;i<n;i++){
        m[nums[i]]++;
    }
    auto compa=[&m](int a,int b){
        return m[a]>m[b];
    };

    priority_queue<int,vector<int>,decltype(compa)>minheap(compa);

    for(auto& pair:m){
        int num=pair.first;
        int frew=pair.second;
        minheap.push(num);
        if (minheap.size() > k){
             minheap.pop();
        }
    }
    vector<int> result;
while (!minheap.empty()) {
    result.push_back(minheap.top());
    minheap.pop();
}

return result;



    
}
string frequencySort(string s) {
    int n=s.size();



    unordered_map<char,int>m;
    for(int i=0;i<n;i++){
        m[s[i]]++;
    };
    
    priority_queue<pair<int,char>>maxheap;// pair sort the arry on abse of first element

    for(auto& pair:m){
        char chara=pair.first;
        int freq=pair.second;

        maxheap.push({freq,chara});

    }
    string ans;
    while(!maxheap.empty()){
        pair<int,char>p=maxheap.top();
        
        char chara=p.second;
        int freq=p.first;
        for(int i=0;i<freq;i++){
            ans+=chara;
        }
        maxheap.pop();

    }
    return ans;

    

  

    
    
}
vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

    int n=points.size();

    auto compa=[](vector<int>a,vector<int>b){

        return (a[0]*a[0]+a[1]*a[1]) <(b[0]*b[0]+b[1]*b[1]) ;
    };
    priority_queue<vector<int>,vector<vector<int>>,decltype(compa)>maxheap(compa);


    for(auto& point:points){

        maxheap.push(point);
        if(maxheap.size()>k){
            maxheap.pop();
        }

    }
    vector<vector<int>> ans;
    while(!maxheap.empty()){
        ans.push_back(maxheap.top());
        maxheap.pop();
        
    }
    return ans;




    
    
}
int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
    int n=profits.size();


    priority_queue<pair<int,int>,vector<pair<int, int>>,greater<>>minheap;
    for (int i = 0; i < n; i++) {
        minheap.push({capital[i], profits[i]});
    }
    priority_queue<int>maxheap;




    while(k--){
        while(!minheap.empty() &&minheap.top().first<=w){
            maxheap.push(minheap.top().second);
            minheap.pop();
        }

        if (maxheap.empty()) break;// if the sbove loop not run then mission over 

        w+=maxheap.top();
        maxheap.pop();

    }
    return w;
    
}
vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

    // suing minheap as for large array and small k values  we not wanna tranvseres the array much 

    typedef pair<int,pair<int,int>>p;// crating a datastruture to tstore the values
    priority_queue<p,vector<p>,greater<p>>minheap;
    vector<vector<int>>ans;
    set<pair<int,int>>visit;

    int n=nums1.size();
    int m=nums2.size();
            if (n == 0 || m == 0 || k == 0) return ans;

    int sum=nums1[0]+nums2[0];

    minheap.push({sum,{0,0}});
    visit.insert({0,0});


    while(k-- && !minheap.empty()){// no need of doing old shit of if size >k then pop
    // now directly add by picking up the minimums using minheap

        auto pairs=minheap.top();
        minheap.pop();
        int i=pairs.second.first;
        int j=pairs.second.second;
        ans.push_back({nums1[i],nums2[j]});

        if(j+1<m && visit.find({i,j+1})==visit.end()){
            minheap.push({nums1[i]+nums2[j+1],{i,j+1}});
            visit.insert({i,j+1});

        }
        if(i+1<n && visit.find({i+1,j})==visit.end()){
            minheap.push({nums1[i+1]+nums2[j],{i+1,j}});
            visit.insert({i+1,j});

        }




    }
    return ans;





    // auto compa=[](vector<int>a,vector<int>b){
    //     return a[0]+a[1]<b[0]+b[1];
    // };
    // priority_queue<vector<int>,vector<vector<int>>,decltype(compa)>maxheap(compa);
    // int n = nums1.size();
    // int m = nums2.size();
    
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         vector<int>ans;
    //         ans.push_back(nums1[i]);

    //         ans.push_back(nums2[j]);
    //         maxheap.push(ans);

    //         if(maxheap.size()>k){
    //             maxheap.pop();
    //         }
    //     }
    // }
    // vector<vector<int>>result;
    // while(!maxheap.empty()){

    //     auto i=maxheap.top();
    //     result.push_back(i);
    //     maxheap.pop();

    // }
    // return result;




    
}

int main(){

    

}