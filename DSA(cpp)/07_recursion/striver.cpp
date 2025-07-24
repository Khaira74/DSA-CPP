#include<iostream>
using namespace std;


//q1 medim

void  helper(int num,vector<string>&ans,string res ){
    if(res.length()==num){
        ans.push_back(res);
        return;
    }
    helper(num,ans,res+"0");
    if(res.empty() || res.back()!='1'){// to avoid consecutive 1's
        helper(num,ans,res+"1");
    }
    
    
}
// or
// After hitting the base case, the local copy of res is cleared automatically when the function returns.
// That’s the beauty of passing by value — it makes recursion simpler when you don’t need to manage state manually.
void helper(int num,vector<string>&ans,string res) {
        if(num==0){
            ans.push_back(res);
            return;
        }
        helper(num-1,ans,res+"0");
        if(res.back()!='1' || res.empty()){
            helper(num-1,ans,res+"1");
        }
        
}


vector<string> generateBinaryStrings(int num){
    vector<string>ans;
     helper(num,ans,"");
    //Write your code
    return ans;
}


//q2
void helper(vector<string>&ans,string res,int open,int close,int n) {
        
        
    if (open == close and open + close == n * 2){

            ans.push_back(res);
            return;
    }  
    if(open<n){
        helper(ans,res+"(",open+1,close,n);
    }                                                                                                                                                                                                                                                                                                                                    
    if( close<open){
        helper(ans,res+")",open,close+1,n);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string>ans;

     helper(ans,"",0,0,n);
    return ans;
    
}


//q3
void helper(string&str,int index,string res,vector<string>&ans){
	if(index>=str.length()){
		if(res.length()>0){
ans.push_back(res);
		}
				return;

		
	}


		helper(str,index+1,res,ans);

	
	char ele=str[index];
	res.push_back(ele);
	helper(str,index+1,res,ans);



}

vector<string> subsequences(string str){
    vector<string>ans;
	 helper(str,0,"",ans);
	return ans;



	
	// Write your code here
	
}
// q5 q6Count all subsequences with sum K
void solve(vector<int>& nums,vector<vector<int>>&ans,
    vector<int>&path,int n,int index) {
        if(index==n){
            ans.push_back(path);
            return;
        }

        path.push_back(nums[index]);
        solve(nums,ans,path,n,index+1);
        path.pop_back();
        solve(nums,ans,path,n,index+1);
        

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>path;
        solve(nums,ans,path,n,0);
        return ans;
        
    }

// Q8 39. Combination Sum

void helper(vector<int>& candidates, int target ,vector<vector<int>>&ans,vector<int>& res,int i,int n) {
    if(target==0){
        ans.push_back(res);
        return;
    }
    if (i >= n) {
        return;
    }

   
    if (target >= candidates[i]) { 
        res.push_back(candidates[i]);
         helper(candidates,target-candidates[i],ans,res,i,n);
        res.pop_back(); // Backtrack
    }
    helper(candidates,target,ans,res,i+1,n);

        


    
}




vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    int n=candidates.size();
    vector<vector<int>>ans;
    vector<int>res;
    helper(candidates,target,ans,res,0,n);
    return ans;

}
// or
void helper(vector<int>& candidates, int target,vector<vector<int>>&ans,int index,vector<int>&res) {
        if(index==candidates.size()){
            if(target==0){
                ans.push_back(res);
            }
            return;

        }
        if(candidates[index]<=target){
            res.push_back(candidates[index]);
            helper(candidates,target-candidates[index],ans,index,res);
            res.pop_back();
        }
        helper(candidates,target,ans,index+1,res);



}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>>ans;
        vector<int>res;

         helper(candidates,target,ans,0,res);
         return ans;
        
}

//q9

// use for loop for non reapting and non subsequence questions
void helper(vector<int>& arr, int target,vector<vector<int>>&ans,vector<int>&temp,int i) {

        if(target==0){
            ans.push_back(temp);
            return;
        }
//         if (i >= arr.size()) {
//              return;
//         }
//         if(arr[i]<=target){  
//             if(!temp.empty() && arr[i]==temp.back()){
//                 i++;
//             }
//                 temp.push_back(arr[i]);
//                 helper(arr,target-arr[i],ans,temp,i+1);

//                 temp.pop_back();
//         }
//         helper(arr,target,ans,temp,i+1);
//    }




    //    we do not want to make same cpmbo with rearanging so we used kas a paramater
    // we 
        for(int k=i;k<arr.size();k++){
        //     //  bwlow condition means that when k=i the staritn node for recusirve loop we include it  but if its the for loop loop we check if it not exixst alredy
            if( k>i && arr[k]==arr[k-1]){
                continue;
            }
            // eg when we use 1 again (after the k=0 loop fully completed and everything is poped out of res )1th index its same like oth index 1 and owuld creat same patter again  like 125 again 17 again 
            
            if(arr[k]<=target){
                temp.push_back(arr[k]);
                helper(arr,target-arr[k],ans,temp,k+1);

                temp.pop_back();
            }
        }

    }

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    int n=candidates.size();
    vector<vector<int>>ans;
    vector<int>res;
    sort(candidates.begin(),candidates.end());

     helper(candidates,target,ans,res,0,n);
     return ans;
    
}

    // q11
    vector<vector<int>> combinationSum3(int k, int n) {

        vector<vector<int>>ans;
        vector<int>arr;
    
         helper(k,n,ans,arr,1);
         return ans;
            
        }
        void helper(int k, int n,vector<vector<int>>&ans,    vector<int>&res,int start) {
    
            if(n<0 || res.size()>k){
                return;
            }
            if(n==0 && res.size()==k){
                ans.push_back(res);
                return;
    
            }
            for(int i=start;i<=9;i++){// Start from 'start' instead of 1 to avoid duplicate elements
                
                    res.push_back(i);
                    helper(k,n-i,ans,res,i+1);// Ensure next number is greater
                    res.pop_back();
                
            }
    
        }
// q12

void solve(string digits,string map[],vector<string>&ans,string &path,int n,int index){
    if(index==n){
        ans.push_back(path);
        return;

    }
    int number=digits[index]-'0';
    string value=map[number];

    for(int i=0;i<value.length();i++){
        path.push_back(value[i]);
        solve(digits,map,ans,path,n,index+1);
        path.pop_back();
    }
    

}

vector<string> letterCombinations(string digits) {
    
    int n=digits.length();



    string map[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string>ans;
    if(n==0){
        return ans;
    }
    string path="";
    solve(digits,map,ans,path,n,0);
    return ans;
     
}
//q10
void helper(vector<int>& nums,    vector<vector<int>>&ans,    vector<int>&res,int n,int index) {
    ans.push_back(res);  // Add the current subset

for(int i=index;i<n;i++){
if(i>index && nums[i]==nums[i-1]){
    continue;
}
res.push_back(nums[i]);
helper(nums,ans,res,n,i+1);
res.pop_back();
}
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {

vector<vector<int>>ans;
vector<int>res;
int n=nums.size();
sort(nums.begin(), nums.end()); // Step 1: Sort to group duplicates

helper(nums,ans,res,n,0);
return ans;

}













// q

bool find(vector<vector<char>>& board, string &word,int i,int j,int index) {
    if(index==word.size()){
        return true;
    }
    int n=board.size();
    int m=board[0].size();

    
    if(i<0 || j<0 || i>=n || j>=m || board[i][j]==' ' || board[i][j]!=word[index]){
        return false;
    }

    // now we have reached ehre it is number of 
    char ch= board[i][j];
    board[i][j]=' ';// as a visited array
    bool res=find(board,word,i+1,j,index+1) ||find(board,word,i-1,j,index+1) ||
    find(board,word,i,j+1,index+1)||find(board,word,i,j-1,index+1);
     board[i][j]=ch;
    return res;

}

bool exist(vector<vector<char>>& board, string word) {
    int n=board.size();
    int m=board[0].size();



    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==word[0] && find(board,word,i,j,0)){
                return true;
            }
        }
    }
    return false;
    
}



//q2


bool valid(string s,int index,int i){
    while(index<=i){
        if(s[index++]!=s[i--]){
            return false;
        }
    }
    return true;
}

void solve(string s,vector<vector<string>>&ans,
vector<string>&path,int index,int n) {
    if(index==n){
        ans.push_back(path);
        return;
    }

    for(int i=index;i<n;i++){
        if(valid(s,index,i)){
            path.push_back(s.substr(index,i-index+1));
            solve(s,ans,path,i+1,n);
            path.pop_back();

        }
    }


}




// N QUEENS



vector<vector<string>> partition(string s) {


    vector<string>path;
    vector<vector<string>>ans;
    int n=s.length();
    solve(s,ans,path,0,n);
    return ans;
    
}



// N QUEENS
bool safe(int row,int col,vector<vector<bool>>&board){

    // checking vertical 
    for(int i=0;i<row;i++){
        if(board[i][col]){
            return false;
        }
    }
    // digonal left 
    int maxleft=min(row,col);
    for(int i=1;i<=maxleft;i++){
        if(board[row-i][col-i]){
            return false;
        }
    }
    // digonal right
    int maxright=min(row,(int)board.size()-col-1);
    for(int i=1;i<=maxright;i++){
        if(board[row-i][col+i]){
            return false;
        }
    }
    return true;



}


void helper(int row,vector<vector<bool>>&board,vector<vector<string>>&res){
    int n=board.size();
    if(row==n){

        vector<string>temp;
        for (int i = 0; i < n; i++) {//rows
            string rowStr = "";
            for (int j = 0; j < n; j++) {//cols
                rowStr += (board[i][j] ? 'Q' : '.');
            }
            temp.push_back(rowStr);
        }
        res.push_back(temp);
        return;


    }


    for(int col=0;col<n;col++){
        if(safe(row,col,board)){
            board[row][col]=true;
            helper(row+1,board,res);
            board[row][col]=false;


        }
    }
}
vector<vector<string>> solveNQueens(int n) {

    vector<vector<bool>>board(n,vector<bool>(n,false));

   vector<vector<string>> res;
    helper(0, board, res);
    return res;





 
}


bool valid(vector<vector<char>>& board,char number,int row,int col) {
    int n=board.size();
    // horizontal
    for(int i=0;i<n;i++){
        if(board[row][i]==number){
            return false;
        }
    }
    for(int i=0;i<n;i++){
        if(board[i][col]==number){
            return false;
        }
    }
    int sqroot=sqrt(board.size());// 9 ka 3 hua
    int rStart=row-row%sqroot;
    int cStart=col-col%sqroot;

    for(int i=rStart;i<rStart+sqroot;i++){
        for(int j=cStart;j<cStart+sqroot;j++){
            if(board[i][j]==number){
                return false;
            }
        }
    }
    return true;
    
}

void helper(vector<vector<char>>& board,bool &solved) {
    if (solved) return; // Stop recursion once solved

    int n=board.size();
    int row=-1;
    int col=-1;
    bool emptyleft=true;// just to exit for loops coz break statemnt works woly with one loop

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]=='.'){
                row=i;
                col=j;
                emptyleft=false;
                break;
            }
        }
        if(!emptyleft){
            break;
        }
    }
    if (emptyleft) { // If no empty cell is found, Sudoku is solved
        solved = true;
        return;
    }



    for(int i=1;i<=9;i++){
        char number=i+'0';
        if(valid(board,number,row,col)){
            board[row][col]=number;
            helper(board,solved);
            if (solved) return; // Stop further recursion once solved

            board[row][col]='.';
            
        }
    }

}


void solveSudoku(vector<vector<char>>& board) {

    bool solved = false;
    helper(board, solved);
    
    
}





















///
void helper(vector<int>& arr,int i,vector<int>&ans,int sum) {
    int n=arr.size();
    if(i==n){
        ans.push_back(sum);
        return;
        
    }
    helper(arr,i+1,ans,sum);
    
    helper(arr,i+1,ans,sum+arr[i]);
}

vector<int> subsetSums(vector<int>& arr) {
    vector<int>ans;
    helper(arr,0,ans,0);
    return ans;
    // code here
}

double myPow(double x, int n) {

    if(n==0){
        return 1.0;
    }
    if(n<0){
        if (n == INT_MIN) {  // coz when we make the iINT MINT postivie it beaocmes a number that is grater than INT_MAX by 1
            return 1 / (myPow(x, -(n + 1)) * x); // Prevent overflow  * exta x for compensating the one power we lost  while-1 doing
        }
        return myPow(1 / x, -n);        
    
    }
    else if(n==0){
        return myPow(x*x,n/2);
    }
    else{
        return x*myPow(x,n-1);

    }        
}





int main(){

}