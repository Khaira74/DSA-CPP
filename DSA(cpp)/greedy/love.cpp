#include<iostream>
using namespace std;




 
class job{
    public:
    int id;
    int deadline;
    int profit;
};
vector<int> JobSequencing(vector<int> &id, vector<int> &deadline,
                          vector<int> &profit) {
                              
                              int n=id.size();
vector<job>jobbb;
for(int i=0;i<n;i++){
    jobbb.push_back({id[i],deadline[i],profit[i]});
}
sort(jobbb.begin(),jobbb.end(),[](job& a,job& b){
    return a.profit>b.profit;
    
});
// using slots coz bool arra
int maxDeadline = 0;
for (int i = 0; i < n; i++) {
        maxDeadline = max(maxDeadline, jobbb[i].deadline);
}
vector<int> slot(maxDeadline + 1, -1);  // -1 means empty slot


int count=0;
int profits=0;
for(auto &i:jobbb){
    for(int j=i.deadline;j>0;j--){
        if(slot[j]==-1){
        profits+=i.profit;
        count++;
        slot[j] = i.id;   // Assign job ID
        break;
        }
    
    }
    
}
return {count,profits};
}

int main(){

}