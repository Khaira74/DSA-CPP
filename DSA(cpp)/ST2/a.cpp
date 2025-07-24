// sorting
#include<iostream>
using namespace std;
// DP-3

//DIAMETER OF TREE
struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode() : val(0), left(nullptr), right(nullptr) {}
         TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
         TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
     };



int helper(TreeNode* root,int&ans) {

    if(root==NULL){
        return 0;
    }

    int left=helper(root->left,ans);
    int right=helper(root->right,ans);

    int temp=max(left,right)+1;
    int res=left+right;// option 2
    ans=max(ans,res);

    return temp;


}
int diameterOfBinaryTree(TreeNode* root) {
    int ans=INT_MIN;


    helper(root,ans);
    return ans;
}
//  max path sum leetcode
int helper(TreeNode* root,int&ans) {

    if(root==NULL){
    return 0;
    }

int left=helper(root->left,ans);
int right=helper(root->right,ans);
left=max(0,left);
right=max(0,right);

int temp=max(left,right)+root->val;
int res=left+right+root->val;// option 2
ans=max(ans,res);

return temp;

}

//  DP2
bool helper(string&s, string&p,int n,int m,vector<vector<int>>&dp) {
    if(n<0 && m<0){
        return true;
    }
    if(n>=0 && m<0){
        return false;
    }
    
    if(n<0 && m>=0){
        for(int k=0;k<=m;k++){
            if(p[k]!='*'){
                return false;
            }
        }
        return true;

    }
    if(dp[n][m] != -1) return dp[n][m];

    if(s[n] == p[m] || p[m] == '?') {
        return dp[n][m] = helper(s, p, n-1, m-1, dp);
    } else if(p[m] == '*') {
        return dp[n][m] = helper(s, p, n-1, m, dp) || helper(s, p, n, m-1, dp);
    } else {
        return dp[n][m] = false;
    }

}

bool isMatch(string s, string p) {
     int n = s.size();
    int m = p.size();

            vector<vector<int>> dp(n, vector<int>(m, -1));


    return helper(s,p,n-1,m-1,dp);
    
}
double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
    auto compa=[](pair<int,int>a,pair<int,int>b){
        double r1 = (double)a.first / a.second;
        double r2 = (double)b.first / b.second;
        return r1 < r2;              
    };
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(compa)>maxheap(compa);
    int n=val.size();
    
    int j=0;
    for(int i=0;i<n;i++){
        
        maxheap.push({val[i],wt[i]});
        
    }
    double total=0;
    while(!maxheap.empty() && capacity>0){
        pair<int,int>topa=maxheap.top();
        maxheap.pop();
        int value=topa.first;
        int weight=topa.second;
        
        if(capacity>=weight){
            total+=value;
            capacity-=weight;
        }
        else{
            total+=(double)capacity*value/weight;
            capacity=0;
            
        }
    }
    return total;
    // code here
    
}

int longestCommonSubsequence(string text1, string text2) {
    int n=text1.size();
    int m=text2.size();



    vector<vector<int>>dp(n+1,vector<int>(m+1,0));


    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(text1[i-1]==text2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
    
}
int lengthOfLIS(vector<int>& nums) {
    int n=nums.size();

    vector<int>dp(n,1);
            vector<int>hash(n,1);

    int maxi=INT_MIN;
    int lastindex=0;

    for(int i=0;i<n;i++){
        hash[i]=i;
        for(int j=0;j<i;j++){
            if( nums[j]<nums[i] && 1+dp[j]>dp[i]){
                dp[i]=dp[j]+1;
                hash[i]=j;
            }
        }
        if(dp[i]>maxi){
            maxi=dp[i];
            lastindex=i;// for the last lement having greateteest value in dp
        }
    }
    vector<int>ans;// the maxi value is the size othw output array
    ans.push_back(arr[lastindex]);// first elemnt of lis== greatest value of dp 
    int index=1;
    while(hash[lastindex]!=lastindex){
        lastindex=hash[lastondex];// updating the value  from hash as it contians the value of ther index from where we begin or ended  the  longest sequence 
        ans.push_back(nums[lastindex]);
    }
    reverse(ans.begin(),ans.end());
    return ans;

    
}

// edit distance 


int maxPathSum(TreeNode* root) {
    int ans=INT_MIN;


helper(root,ans);
return ans;
}



// DP1
int longestCommonSubstr(string& s1, string& s2) {
        
    int n=s1.size();
    int m=s2.size();
    
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    int maxi=0;
    
    
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
                maxi=max(maxi,dp[i][j]);
            }
            else{
                dp[i][j]=0;
            }
            
        }
    }
    return maxi;
    // your code here
    
}





//HASHMAPS
int longestKSubstr(string &s, int k) {
        
    int i=0;
int j=0;
int n=s.length();
if(n==1){
return 1;
}
unordered_map<char,int>m;
int maxi=-1;

while(j<n){
m[s[j]]++;
if(m.size()>k){
    m[s[i]]--;
    if(m[s[i]]==0){
        m.erase(s[i]);
    }
    i++;

}
if(m.size()==k){
    maxi=max(maxi,j-i+1);
}

    
    
    j++;




}
return maxi;
// your code here
}
string minWindow(string s, string t) {

    int n=s.size();
    int m=t.size();
    if(m>n){
        return "";
    }

    vector<int>v(128,0);
    for(int i=0;i<m;i++){
        v[t[i]]++;
    }

    int left=0;
    vector<int>counter(128,0);
    int len=INT_MAX;
    int startIndex=0;
    int have=0;
    for(int right=0;right<n;right++){

        char ch=s[right];
        counter[ch]++;

        if(v[ch]>0 && v[ch]>=counter[ch]){
            have++;
        }
        while(have==m){

            if(right-left+1<len){
                len = right - left + 1;
                startIndex = left;
            }

            char eleminate=s[left];
            // we sued while loop ehen have == ma nd have value will only reduce if the counter will contain the only less or euqal value than he v array 
            if(v[eleminate]>0 && v[eleminate]>=counter[eleminate]){
                have--;
            }
            counter[eleminate]--;
            left++;
        }

    }
    if(len==INT_MAX){
        return "";

    }
    return s.substr(startIndex,len);
    
}
int lengthOfLongestSubstring(string s) {
    int i=0;
    int j=0;
    int n=s.length();
    unordered_map<char,int>m;
            int maxi=0;

    while(j<n){
        m[s[j]]++;
        if(m.size()<j-i+1){
            m[s[i]]--;
            if(m[s[i]]==0){
                m.erase(s[i]);
            }
            i++;
        }
        if(m.size()==j-i+1){
            maxi=max(maxi,j-i+1);
        }
        j++;
    }
    return maxi;

    
}


// priority queue







class Node{
    public:
    int data;
    Node*right;
    Node*left;
    
    Node(int data){
        this->data=data;
        this->right=NULL;
        this->left=NULL;
    }
};
class Solution {
  public:
  
    void transverse(Node*head, vector<string>&ans,string s) {
        if(head->left==NULL && head->right==NULL){
            ans.push_back(s);
            return;
        }
        transverse(head->left,ans,s+'0');
        transverse(head->right,ans,s+'1');
    }

    vector<string> huffmanCodes(string S, vector<int> f, int N) {
        // Code here
            
        auto compa=[](Node*a,Node*b){
            return a->data>b->data;
        };
        
        
        
        priority_queue<Node*,vector<Node*>,decltype(compa)>minheap(compa);
        
        
        for(int i=0;i<N;i++){
            Node*temp=new Node(f[i]);
            minheap.push(temp);
        }
        
        while(minheap.size()>1){
            Node*lefti=minheap.top();
            minheap.pop();
            Node*righti=minheap.top();
            minheap.pop();
            Node*tempo=new Node(lefti->data+righti->data);
            minheap.push(tempo);
            tempo->left=lefti;
            tempo->right=righti;

        }
        Node*head=minheap.top();
        vector<string>ans;
        string res="";
        transverse(head,ans,res);
        return ans;
    }
};


int activitySelection(vector<int> &start, vector<int> &finish) {
    // code her
    auto compa=[](const pair<int,int>&pair1,const pair<int,int>&pair2){
        return pair1.second>pair2.second;
        
    };
    priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(compa)>minheap(compa);
    for(int i=0;i<start.size();i++){
         minheap.push({start[i],finish[i]});
    }
    int count=0;
    int before=0;
    while(!minheap.empty()){
        pair<int,int>p=minheap.top();
        minheap.pop();
        
        if(p.first>before){
            count++;
            before=p.second;
        }
        
        
    }
    
    return count;
}
int main(){
    
}