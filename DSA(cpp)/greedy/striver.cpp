#include<iostream>
using namespace std;


//fractional  knapsack

/// using comparator

struct Item{
    int value;
    int weight;
};


class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, 
    int capacity) {
        int n=val.size();
        vector<Item>itema;
        for(int i=0;i<n;i++){
            itema.push_back({val[i],wt[i]});
        }
        sort(itema.begin(),itema.end(),[](const Item& a,const Item& b){
            return (double) a.value/ a.weight > (double)b.value/b.weight;
        });
        
        double total=0.0;
        double remain=capacity;
        for(auto &items:itema){
            if(items.weight<=remain){
                total+=items.value;
                remain-=items.weight;
                
            }
            else{
                total+=(double)remain * items.value/items.weight;
                break;
            }
        }
        return total;
    }
};
int candy(vector<int>& arr) {
    int n = arr.size();
     if (n == 0) return 0;

     int count = n;  // Base case: every child gets at least 1 candy // no need to add in bse condioon lop
     int i = 1;

     while (i < n) {
         if (arr[i] == arr[i - 1]) {  
             i++;  // No extra candy needed
             continue;
         }

         // Count increasing sequence
         int up = 0;
         while (i < n && arr[i] > arr[i - 1]) {
             up++;
             count += up;  // Add extra candies
             i++;
         }

         // Count decreasing sequence
         int down = 0;
         while (i < n && arr[i] < arr[i - 1]) {
             down++;
             count += down;  // Add extra candies
             i++;
         }

         // Remove double counting of the peak (middle child)
         count -= min(up, down);
     }

     return count;
 }


 class meet{
    public:
    int starts;
    int end;
};


// Function to find the maximum number of meetings that can
// be performed in a meeting room.

int maxMeetings(vector<int>& start, vector<int>& end) {
    
    int n=start.size();
    vector<meet>meeting;
    for(int i=0;i<n;i++){
        meeting.push_back({start[i],end[i]});
        
    }
    sort(meeting.begin(),meeting.end(),[](meet& a,meet& b){
        return a.end<b.end;
    });
    
    int count=1;
    int limit=meeting[0].end;
    for(int i=1;i<n;i++){
        if(meeting[i].starts>limit){
            count++;
            limit=meeting[i].end;
        }
    }
    return count;
    
    
    
    // Your code here
}
class intervals{
    public:
    int start;
    int end;

};

int eraseOverlapIntervals(vector<vector<int>>& arr) {

    int n=arr.size();
    vector<intervals>meeting;
    for(int i=0;i<n;i++){
        meeting.push_back({arr[i][0],arr[i][1]});
    }
    sort(meeting.begin(),meeting.end(),[](intervals& a,intervals& b){
        return a.end<b.end;
    });


    int count=0;
    int limit=meeting[0].end;
    for(int i=1;i<n;i++){
        if (meeting[i].start >= limit) {  
            // ✅ Non-overlapping case → update limit
            limit = meeting[i].end;
        } else {
            // ❌ Overlapping case → remove the current interval
            count++;  
        }
    }
    return count;
}
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>>ans;

int n=intervals.size();
if(n==0){
 ans.push_back(newInterval); 
 return ans;
}
int i=0;

while(i<n && intervals[i][1]<newInterval[0]){
    ans.push_back(intervals[i]);
    i++;
}
//intervals[i][1]>newInterval[i][0]. is already included below coz thats why the above loop stopped
while(i<n && intervals[i][0]<=newInterval[1]){// 1st index is checked now its turn to check 0th index of the interval usinh this loop

    newInterval[0]=min(intervals[i][0],newInterval[0]);

    newInterval[1]=max(intervals[i][1],newInterval[1]);
    i++;

}
ans.push_back(newInterval);
while(i<n){
    ans.push_back(intervals[i]);
    i++;
}


return ans;
}

    


int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(),g.end());
    sort(s.begin(),s.end());
    int n=g.size();
    int m=s.size();
    int i=0;
    int j=0;
    int count=0;
    while(i< n && j<m){
        if(g[i]<=s[j]){
            count++;
            i++;
        }
        j++;
    }
    return count;
}
// this is not simple that we would just keep adding the arr elements

long long solve(vector<int>& bt) {
    long long n=bt.size();
    sort(bt.begin(),bt.end());
    long long wait=0;
    long long time=bt[0];
    for(int i=1;i<n;i++){
        wait+=time; // this comes first   coz for last element waiting time would not reawuire to add its value 
                    time+=bt[i];

        
    }
    
    return wait/n;
    // code here
}
bool canJump(vector<int>& arr) {
        
    int n=arr.size();

        int maxJump=0;
    for(int i=0;i<n;i++){
        if(i>maxJump){// whne i will surpass the max jump means we were unabale to jump forward 
            return false;
        }
        
        int jump=arr[i];

        maxJump=max(maxJump,jump+i);// mark the max jump we can 
        // if(maxJump!=maxJump){
        //     maxJump+=maxJump;
        // }
      
        
    }
    return true;
    
}
// jump2
int jump(vector<int>& nums) {

    int n=nums.size();
    if(n<=1){
        return 0;
    }
    int count=0;
    int jumps=INT_MIN;
    int end = 0;

    for(int i=0;i<n;i++){
        
        jumps=max(nums[i]+i,jumps);
        if(i==end){
            end=jumps;
            count++;
            if(end>=n-1){
                break;
            }
        }
    }
    return count;
    
}
int main(){

}