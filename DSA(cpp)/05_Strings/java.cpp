#include<iostream>
using namespace std;




// maxing occcuring cahharcter

char occur(string s){
    int arr[26]={0};
    for(int i=0;i<s.length();i++){
        int asnwer=0;
        if(arr[i]>'a' || arr[i]<'z'){
             asnwer=s[i]-'a';

        }
        else{
             asnwer=s[i]-'A';

        }
        arr[asnwer]++;

    }
    int maxi=-1;
    int index=0;
    for(int i=0;i<26;i++){
        if(maxi<arr[i+1]){
            index=i;
            maxi=arr[i];

        }
    }
    char  ok='a'+index;
    return ok;
 


}
//valid anagram
// o(n)
bool isAnagram(string s, string t) {
    int n=s.length();
    int m=t.length();
    if(n!=m){
        return false;
    }
    int count[26];
    for(int i=0;i<n;i++){
        count[s[i]-'a']++;
    }
    
    for(int i=0;i<n;i++){
        count[t[i]-'a']--;
    }
    for(int i=0;i<26;i++){
        if(count[i]!=0){
            return false;
        }
    }
    return true;
}

// o(1)time conleixty
bool isPalindrome(string s) {
    int left=0;
    int right=s.size()-1;
    while(left<right){
        //alnum for alphanumericin check 0-9,a-z,A-Z
        while(left<right && !isalnum(s[left])){
            left++;
        }

        while(left<right && !isalnum(s[right])){
            right--;
        }
        if(tolower(s[left])!=tolower(s[right])){
            return false;
        }
        left++;
        right--;
    }
    
    return true;
}

// valid palindrome 2
// O(n)time cpmleixty constant spcae
bool isPalindrome(string &s, int left, int right) {
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}
    bool validPalindrome(string s) {
         int left = 0, right = s.size() - 1;
    
    while (left < right) {
        if (s[left] != s[right]) {
            // Try skipping left or right character
            return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
        }
        left++;
        right--;
    }
    
    return true;
        
    }

// O(1)  time compl3xity
    int compress(vector<char>& chars) {
        int i=0;
        int index=0;
        int n=chars.size();
        while(i<n){
            char curr=chars[i];// saving the starting index of every chractwer 
            int count=0;
            
            while(i<n && chars[i]==curr){
                i++;
                count++;
            }
            // while loop over menas curr!=chars[i]



            // as index starting from 0 so we creating sbace for char before tyoing its count
            // also for chars countless than =1
            chars[index++] = curr;


            
                //
                if(count>1){
                    for (char c : std::to_string(count)) {
                      chars[index++] = c;
                    }
                    
                }
               

            
            
            
        }
        return index;
        
        
    }

    

    bool isLongPressedName(string name, string typed) {

        int i=0;
        int j=0;
        int n=name.size();
        int m=typed.size();
        while(i<n && j<m){
            if(name[i]==typed[j]){
                i++;
                j++;
            }
            else{
                if(i>0 && typed[j]==name[i-1]){
                    j++;

                }
                else{
                    return false;

                }
            }
        }
        //as  now i value is ==n

        while(j<m){
            if(typed[j]!=name[i-1]){
                return false;

            }
            j++;
        }
        if(i<n){
            return false;

        }
        return true;



        
    }


    bool valid(int arr[],int n){
        for(int i=0;i<n;i++){
            if(arr[i]!=0){
                return false;

            }
        }
        return true;
    }
    int search(string &pat, string &txt) {
        
        
        int count[26]={0};
        for(int i=0;i<pat.size();i++){
            
            count[pat[i]-'a']++;
        }
        
        int i=0;
        int j=0;
        int ans=0;
        int k=pat.size();
        int n=txt.size();
        
        while(j<n){
            
                count[txt[j]-'a']--;
                if(j-i+1==k){
                    if(valid(count,26)){
                        ans++;
                    }
                    count[txt[i]-'a']++;
                    i++;
                }
                j++;
            
        }
        return ans;
        
        
        // code here
    }



    // string matching
    #define PRIME 101;
    long long hashcode(string&text,long long n){
        long long hash=0;
        for(long long i=0;i<n;i++){
            hash=(hash*256+text[i])%PRIME;
        }
        return hash;


    }

    void karpRobin(string &text,string&pattern){


        int n=text.size();
        int m=pattern.size();
        if(m>n){
            return;
        }
        long long patternhash=hashcode(pattern,m);// hascode for pattern

        long long texthash=hashcode(text,m);//hashcode for text of size of pattern
        int highestPow=0;
        for (int i = 0; i < m - 1; i++) {
            highestPow = (highestPow * 256) % PRIME;
        }
        int left = 0, right = m - 1;  // Two pointers for sliding window

        while (right < n) {
            // If hash matches, verify actual substring (Las Vegas version)
            if (patternhash == texthash) {
                if (text.substr(left, m) == pattern) {  // Verify substring
                    cout << "Pattern found at index " << left << endl;
                }
            }
    
            // Compute rolling hash for next window
            if (right + 1 < n) {
                texthash = (texthash - text[left] * highestPow) * 256 + text[right + 1];
                texthash = (texthash % PRIME + PRIME) % PRIME; // Ensure non-negative
            }
    
            // Move both pointers
            left++;
            right++;
        }


    }
    int strStr(string haystack, string needle) {
        

        int n=haystack.size();
        int m=needle.size();
        if(n<m){
            return -1;
        }
        vector<int>lps(m);
        int i=0;
        int j=1;
        while(j<m){
            if(needle[i]==needle[j]){
                lps[j]=i+1;
                j++;
                i++;
            }
            else{

                if(i==0){
                    lps[j]=0;
                    j++;
                }
                else{
                    i=lps[i-1];
                }
            }

        }
        int pati=0;
        int texti=0;
        while(texti<n){
            if(haystack[texti]==needle[pati]){

            pati++;
            texti++;

            }
            if(pati==m){
                return texti-pati;



            }
            if(texti<n && haystack[texti]!=needle[pati]){
                if(pati==0){
                    texti++;
                }
                else{
                    pati=lps[pati-1];
                }
            }
        }
        return -1;
        
    }

int main(){
    
}