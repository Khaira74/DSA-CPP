#include<iostream>
using namespace std;
#include<vector>
#include<set>

// graphs 

// creating adjecy list from adjency matrix 

// coz of this we added a for loop first
// Sample Input 1:
// 4 3
// 1 2
// 0 3
// 2 3
// Sample Output 1:
// 0 3
// 1 2
// 2 1 3
// 3 0 2
vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    // Write your code here.
    vector<vector<int>> adjList(n);  // Initialize adjacency list
    for (int i = 0; i < n; i++) {
        adjList[i].push_back(i);
    }

    for (auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];

        adjList[u].push_back(v);  // Add edge u ? v
        adjList[v].push_back(u);  // Add edge v ? u (since it's undirected)
    }

    // Sorting each adjacency list for consistent output
    

    return adjList;

}











// bfs is called only one time from main funciton so no needd fpr loo[]
void bfs(vector<vector<int>>&list,vector<bool>&visit,int node,vector<int>&ans){

    visit[node]=true;
    queue<int>q;
    q.push(node);
    while(!q.empty()){
        int front=q.front();
        q.pop();
        ans.push_back(front);
        for(auto neighbour:list[front]){
            if(!visit[neighbour]){
                visit[neighbour]=true;
                q.push(neighbour);

            }
        }

    }
}
vector<int> bfsTraversal(int n, vector<vector<int>> &adjList){
    // vector<vector<int>>adjList(n);
    // for(auto &i:adj){
    //     int u=i[0];
        
    //     int v=i[1];
    //     adjList[u].push_back(v);

    // }


    vector<int>ans;

    vector<bool>visit(n,false);

     if (!visit[0]) {
        bfs(adjList, visit, 0, ans);
    }

    return ans;


    // Write your code here.
}





// cycle detettcion
//1 undirected graph
bool detect(int node,vector<bool>vis,vector<vector<int>>& adj){
    vector<int>parent(adj.size(),-1);
    vis[node]=true;
    queue<int>q;
    q.push(node);
    while(!q.empty()){
        int front=q.front();
        q.pop();
        for(int neighbour:adj[front]){
            if(vis[neighbour] &&neighbour!=parent[front]){
                return true;
            }
            if(!vis[neighbour]){
                q.push(neighbour);
                vis[neighbour]=true;
                parent[neighbour]=front;
            }
        }
    }
    return  false;
    
}
bool isCycle(vector<vector<int>>& adj) {
    int n=adj.size();
    
   vector<bool>vis(n);
   for(int i=0;i<n;i++){
       if(!vis[i]){
       if(detect(i,vis,adj)){
           return true;
       }
       }
   }
   return false;
    // Code here
}


//2 directed graph

bool detect(int node,vector<bool>vis,vector<vector<int>>& adj,vector<bool>adjVis){
        
    adjVis[node]=true;
    vis[node]=true;
    for(int neighbour:adj[node]){
        if(!vis[neighbour]){
            bool ans=detect(neighbour,vis,adj,adjVis);
            if(ans){
                return true;
            }
        }
        else if(adjVis[neighbour]){
            return true;
            
        }
    }
    adjVis[node]=false;
    return false;
    
}

// Function to detect cycle in a directed graph.
bool isCyclic(vector<vector<int>> &adj) {
    
     int n=adj.size();
    
   vector<bool>vis(n);
   vector<bool>adjVis(n);
   for(int i=0;i<n;i++){
       if(!vis[i]){
       if(detect(i,vis,adj,adjVis)){
           return true;
       }
       }
   }
   return false;
    // code here
}




// topological sort
// usig dfs
void sort(int node,vector<bool>&vis,vector<vector<int>>& adj,stack<int>&s){
        
    vis[node]=true;
    for(int neighbour:adj[node]){
        if(!vis[neighbour]){
           sort(neighbour,vis,adj,s);
        }
    }
    s.push(node);
    
}
vector<int> topologicalSort(vector<vector<int>>& adj) {
    
   int n=adj.size();
    
   vector<bool>vis(n); 
   stack<int>s;
   for(int i=0;i<n;i++){
       if(!vis[i]){
            sort(i,vis,adj,s);
       }
   }
   vector<int>ans;
   while(!s.empty()){
       ans.push_back(s.top());
       s.pop();
   }
   return ans;
    // Your code here
}

/// using bsf and indrgree
vector<int> topologicalSort(vector<vector<int>>& adj) {
    int n=adj.size();
    vector<int>ans;
    vector<int>indegre(n,0);
    for(int i=0;i<n;i++){
        for(auto j:adj[i]){
            indegre[j]++;
        }
    }
    queue<int>q;

    for(int i=0;i<n;i++){
        if(indegre[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int front=q.front();
        q.pop();
        ans.push_back(front);
        for(auto neighbour:adj[front]){
            
            indegre[neighbour]--;
            if(indegre[neighbour]==0){
                q.push(neighbour);
            }
        }
        
    }
    return ans;

    // Your code here
}


//shortest paths 
// undirected graph
// usng bsic bsf and then using parent array
vector<int> shortestPath(vector<vector<int>>& adj, int src) {
    int n=adj.size();
    
    
    vector<int>ans(n,-1);
    vector<bool>vis(n,false);
    vector<int>parent(n,-1);
    queue<int>q;
            ans[src]=0;

    q.push(src);
    vis[src]=true;
    parent[src]=-1;
    
   while (!q.empty()) {
        int front = q.front();
        q.pop();
        for (auto neighbour : adj[front]) {
            if (!vis[neighbour]) {
                vis[neighbour] = true;
                parent[neighbour] = front;
                q.push(neighbour);
            }
        }
    }

    for (int i = 0; i < adj.size(); i++) {
        if (vis[i]) {  // Only process reachable nodes
            int currnode = i;
            int count = 0;
            while (currnode != src && parent[currnode] != -1) {
                currnode = parent[currnode];
                count++;
            }
            ans[i] = count;
        }
    }
    ans[src] = 0;
    return ans;
    
    
    // code here
}
// 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    vector<pair<int,int>>adjList;
    for(int i=0;i<edges;i++){
        int u=vec[i][0];

        int v=vec[i][1];

        int w=vec[i][2];
        adjList[u].push_back(make_pair(v,w));

        adjList[v].push_back(make_pair(v,w));
    }

    set<pair<int,int>>s;// to store the min distance nodes 
    vector<int>distance(edges,INT_MIN);// stores disatnce from source

    distance[0]=0;// for source
    s.insert(make_pair(0,source));// for soruce 
    while(!s.empty()){
        auto front=*(s.begin());
        int weight=front.first;// the weight 
        int dest=front.second;// the min distace 
        for(auto neighbour:adjList[dest]){// checking and movinf forward to its connected nodes 
            if(weight+neighbour.second<distance[neighbour.first]){// if the new distance is less thean present in disance array it
                // means in future it could give even more smalleser results
                auto record=s.find(make_pair(distance[neighbour.first],neighbour.first));// check if already present
                if(record!=s.end()){
                    s.erase(record);
                }

                distance[neighbour.first]=weight+neighbour.second;
                s.insert(make_pair(distance[neighbour.first],neighbour.first));
            }

        }

    }
    return distance;
}




// BELLMAN FORD https://www.naukri.com/code360/problems/bellmon-ford_2041977?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {



    vector<int>distance(n+1,1e8);// n+1 as for the ndoes as strauinf from 1 not 0
    distance[src]=0;
    // for n-1 times


    vector<int>distance(n+1,1e8);// n+1 as for the ndoes as strauinf from 1 not 0
    distance[src]=0;
    // for n-1 times


    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
         int u=edges[j][0];
        int v=edges[j][1];
        int wt=edges[j][2];

            if(distance[u]!=1e9 && (distance[u]+wt) <distance[v]){
                distance[v]=distance[u]+wt;

            }
        }
       

    }
    bool flag=0;
    for(int j=0;j<m;j++){
         int u=edges[j][0];
        int v=edges[j][1];
        int wt=edges[j][2];

            if(distance[u]!=1e8 && (distance[u]+wt) <distance[v]){
                flag=1;

            }
    }
    if(flag==0){
        return distance;
    }
    return distance;
    // Write your code here.
}


// floyd marshall https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implementing-floyd-warshall
void shortestDistance(vector<vector<int>>& mat) {
    int n=mat.size();
    // setting -1 to infinity
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==-1){
                mat[i][j]=1e9;
            }
            if(i==j){
                mat[i][j]=0;
            }
        }
    }
    // checking for eack node path
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
            }
        }
    }
        
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==1e9){
                mat[i][j]=-1;
            }
        }
    }
    // Code here
}

int main(){
    int n;
    int m;
    vector<vector<int>>list(n);
    cin>>n;
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>list[i][0];
        cin>>list[i][1];
    }
    vector<vector<int>> adjList = printAdjacency(n, m, list);

    // Print adjacency list
    for (int i = 0; i < n; i++) {
        cout << i;
        for (int neighbor : adjList[i]) {
            cout << " " << neighbor;
        }
        cout << endl;
    }

    return 0;




}