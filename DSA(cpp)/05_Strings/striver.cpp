
#include<iostream>
using namespace std;

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

//                                         EASY/MEDIUM

//Q1





/// brute approcah
// suign stl;y




string reverseWordss(string s) {

    stringstream ss(s);
    string token="";

    string result="";
    while(ss>>token){

        result=token+""+result;


    }
    return result.substr(0,result.length()-1);

}


// optimal appriach
 string reverseWords(string s) {
        reverse(s.begin(),s.end());

        int i=0;// mian index
        int r=0;// right that wil work twith i
        int l=0;// left that will start point of the word to be reversd
        while(i<s.length()){
            while(i<s.length() && s[i]!=' '){
                s[r++]=s[i++];
             
            }
            if(l<r){
                reverse(s.begin()+l,s.begin()+r);
                s[r]=' ';
                r++;

                l=r;

            }
            i++;
        }
        s=s.substr(0,r-1);
        return s;
        
    }


    int maths(int arr[]){
        int maxi=-1;
        int mini=1e9;

        for(int i=0;i<26;i++){
            maxi=max(maxi,arr[i]);

            if(arr[i]>0){
                mini=min(mini,arr[i]);
            }
        }
        return maxi-mini;

    }


    int beautySum(string s) {
        int n=s.length();
        int count=0;


        for(int i=0;i<n;i++){

            int freq[26]={0};
            for(int j=i;j<n;j++){

                freq[s[j]-'a']++;

                count+=maths(freq);


            }
        }
        return count;
        
    }

 // count substring with k disticnt character 
// brute
int countSubstrs(string& s, int k) {
        // int n=s.length();
        // int ans=0;
    
        
        
        // for(int i=0;i<n;i++){
        //     map<int,int>maps;
        //     int count=0;

            
            
        //     for(int j=i;j<n;j++){
        //         if(maps.find(s[j]-'a')==maps.end()){
        //             count++;
        //         }

        //         maps[s[j]-'a']++;
        //         if(count==k){
        //             ans++;
                    
        //         }
        //         if(count>k){
        //             break;
        //         }

                
                
        //     }
        // }
        // return ans;
        // code here.
          int n = s.length();
    int ans = 0;

    for (int i = 0; i < n; i++) {
        // Use a frequency array instead of a map
        int freq[26] = {0};
        int count = 0;

        for (int j = i; j < n; j++) {
            // Add the current character
            if (freq[s[j] - 'a'] == 0) {
                count++;
            }
            freq[s[j] - 'a']++;

            // Check if the substring has exactly k distinct characters
            if (count == k) {
                ans++;
            }
            
            // Break if the number of distinct characters exceeds k
            if (count > k) {
                break;
            }
        }
    }

    return ans;
 }


    // optima 2 pointer

int countSubstr(string& s, int k) {
    int  result=atmost(s,k)-atmost(s,k-1);
    return result;
    
}
 int atmost(string&s,int k){
         int DIScount=0;// for the value of k
    int n=s.length();
    int i=0;
    int j=0;
    int freq[26]={0};
    int ans=0;
    while(j<n){
        freq[s[j]-'a']++;
        if(freq[s[j]-'a']==1){
            DIScount++;
        }
        while(DIScount>k){
            freq[s[i]-'a']--;
            if(freq[s[i]-'a']==0){
                DIScount--;
            }
            
            i++;
        }
        ans+=j-i+1; // no of substring can be the the current index- starting index
        
        j++;
    }
    return ans;
}
// string to char
int myAtoi(string s) {
        int i=0;
        int n=s.length();
        long ans=0;
        while(i<n && s[i]==' '){// remoivng extrea empty space form fornt
            i++;
        }
        int sign=1;
        if (i < n && (s[i] == '-' || s[i] == '+')) {
    if (s[i] == '-') {
        sign = -1;
    } else {
        sign = 1;
    }
    i++;
}
        int mini=INT_MIN;
        int maxi=INT_MAX;
         while (i < n && s[i] == '0') {
        i++; // Skip leading zeros
    }
        while(i<n){
            if(s[i]==' ' || !isdigit(s[i])){// loop end if there is alphabet or first elemnt in empty
                break;
            }
            ans=ans*10+(s[i]-'0');
            if(sign*ans<=mini){
                return mini;
            }
            if(sign*ans>=maxi){
                return maxi;
            }
            i++;
            
        }
        return (int)sign*ans;
        
    }
int maxDepth(string s) {
        int n=s.length();
        
        int count=0;
        int maxi=0;
        int i=0;
        while(i<n){
            if(s[i]=='('){
                count++;

            }
            

            else if(s[i]==')'){
                count--;
            }
                        maxi=max(maxi,count);

            i++;
        }
        return maxi;
        
    }
int main(){

}