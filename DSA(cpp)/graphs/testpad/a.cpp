#include<iostream>
#include<vector>

using namespace std;
// Find path in a directed graph bookmark_border
// Given a directed graph and two vertices(say source and destination vertex), check whether there exists some path from the given source vertex to the destination vertex or not. If it exists then print “YES”, else print “NO”.

// Input Format:

// First line contains two space separated integers V, E denoting the number of vertices and edges in the graph.
// Following E lines contain two space separated integers u, v denoting a directed edge from u to v.
// Last line contains two space separated integers src, dest denoting the source and destination vertex


bool check(int src,vector<vector<int>>&adjMatrix,vector<bool>vis,int dest){
    vis[src]=true;
    queue<int>q;
    q.push(src);
    while(!q.empty()){
        int front=q.front();
        q.pop();
        for(int neighbour:adjMatrix[front]){
            if(!vis[neighbour]){
                q.push(neighbour);
                vis[neighbour]=true;
            }
        }
        
    }
    if(vis[dest]){
        return true;
    }
    return false;
}
int main(){
      int V;
    int E;
    cin>>V;
    cin>>E;
    vector<vector<int>>adjMatrix(V);
    
    int u;
    int v;
    for(int i=0;i<E;i++){
        cin>>u;
        cin>>v;
        adjMatrix[u].push_back(v);

        
    }
    int src;
    int dest;
    cin>>src;
    cin>>dest;
   
    vector<bool>vis(V,false);
    // checking only for the souce instead of full whole for loop 
    
    
    if( check(src,adjMatrix,vis,dest)  ){
                        cout<<"YES"<<endl;

     }
      else{ 
          cout<<"NO"<<endl;
      }
    
  
}


//////////////////////////////////////
//////////////////////////////////////

////////////////////////////////////////////////////////////////   SEM 6 ////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////
//////////////////////////////////////
//////////////////////////////////////
//////////////////////////////////////
int number_of_edges(int n) {
    
    vector<vector<int>>adjList(n+1);
    
    for(int i=1;i<=n;i++){
        
        for(int j=i;j<=n;j++){
            
        
        int u=i;
        int v=j;
        if(v==u+1 || v==3*i){
            adjList[u].push_back(v);
        }
        }
    }
        vector<bool>vis(n+1,false);
        
        vector<int>parent(n+1,-1);
        
        queue<int>q;
        q.push(1);
    vis[1]=true;
        while(!q.empty()){
            int front=q.front();
            q.pop();
            
            for(int neighbour:adjList[front]){
                
                if(!vis[neighbour]){
                    parent[neighbour]=front;
                    vis[neighbour]=true;
                    q.push(neighbour);
                }
                
            }
        }
            
        
    int count=0;
        
            int currNode=n;
            
            while(vis[currNode] && currNode!=1 && parent[currNode]!=-1){
                count++;
                currNode=parent[currNode];
            
            }
        //if (currNode != 1) return -1;  // No path found

        return count;
    
    
    
    
    
  // write code here  
}

int main(){

}