


import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

// if  n= no of nodes than m== no of edges
// m=n+1// always




// #1 if we start from a node and end at that node then we call it cyclic
// #2 if we start from a node and not  end at that node then we call it acyclic



// degree- degree of a node is thje no of edged comig in ir out of the node
// total degree of graphj== 2* no of nodes




public class a {
    public static void main(String[] args) {


        int n=3;
        int m=3;
                
        // taking input iusing adjency matrix




        int adj[][]=new int[n+1][m+1];// as the numbers n and m are  gneral number not index numebers that we start from 0 so to mark them in matrix we haev ot make array till n+1// as the index start from 0


        adj[1][2]=1;
        adj[2][1]=1;

        adj[2][3]=1;
        adj[3][2]=1;
        
        adj[1][3]=1;
        adj[3][1]=1; 




        //// taking inputusing arraylist
        /// 
        /// 
        /// 
        /// definig visually for user to understand the concept 
        ///  
        // ArrayList<ArrayList<Integer>>adjs=new ArrayList<ArrayList<Integer>>();
        // for(int i=0;i<=n;i++){
        //     adjs.add(new ArrayList<Integer>());
        // }
        // adjs.get(1).add(2);
        // adjs.get(2).add(1);

        // adjs.get(2).add(3);
        // adjs.get(3).add(2);

        // adjs.get(1).add(3);
        // adjs.get(3).add(1);




        // for(int i=1;i<n;i++){
        //     for(int j=0;j<adjs.get(i).size();i++){
        //         System.out.println(adjs.get(i).get(j)+" ");
        //     }
        //     System.out.println();
        // }




        //taking inpirt from user 

        Scanner input=new Scanner(System.in);
        System.out.println("enter no of vertices");

        int vertex=input.nextInt();
        System.out.println("enter no of edges");
        
        int edge=input.nextInt();
        List<List<Integer>>adjList=new ArrayList<>();
        for(int i=0;i<vertex;i++){
            adjList.add(new ArrayList<>());

        }
        for (int i = 0; i < edge; i++) {
            int source = input.nextInt();
            int destination = input.nextInt();
            addEdge( source, destination,adjList); //see below
        }

    }
    //  defing ghraph
    static void addEdge(int u,int v,List<List<Integer>>adjList){
        adjList.get(u).add(v);
        
        adjList.get(v).add(u);
    }

    static void print(List<List<Integer>>adjList){
        for(int i=0;i<adjList.size();i++){
            System.out.println("vertex"+i+"->");
            for(int neighbour:adjList.get(i)){
                System.out.println(neighbour+" ");
            }
            System.out.println();
        }

    }



    // dfs

















    // bfs
    public ArrayList<Integer> bfsrTransversal(ArrayList<ArrayList<Integer>>adjs,int v){
        ArrayList<Integer>bfs=new ArrayList<>();// stores the lements in order 
        boolean vis[]=new boolean[v];// boolean fucntion to mark the elements os that not repeat


        Queue<Integer>q=new LinkedList<>();// queue to add and remove the elements 

        q.add(0);
        while(!q.isEmpty()){
            Integer node=q.poll();
            bfs.add(node);

            // to check for neighbour elemnts  and adding in the queue
            for(Integer it:adjs.get(node)){// searchin till taht index
                if(vis[it]==false){
                    vis[it]=true;
                    q.add(it);
                }

            }
        }
        return bfs;

    }
    // dfs



    
    public static void dfs(int node,boolean vis[],ArrayList<ArrayList<Integer>>adjs,ArrayList<Integer> ls){
        vis[node]=true;
        ls.add(node);
        for(int it:adjs.get(node)){
            if(vis[it]==false){
                dfs(it, vis, adjs, ls);
            }
        }
    }
    public ArrayList<Integer> dfsrTransversal(ArrayList<ArrayList<Integer>>adjs,int v){
        boolean vis[]=new boolean[v+1];
        vis[0]=true;
        ArrayList<Integer> ls=new ArrayList<>();
        dfs(0,vis,adjs,ls);
        return ls;
    }
    // dfs
    // in bfs we have for loop which  runs for loopa nd adds the lements but here we not wait and keep adding elemnts in the queue
















    // cycle detection
    // uisng bfs 
    // adjency matrix given

     public static boolean isCyclic (int src,Boolean[]visit,List<List<Integer>>adjList) {
        int []parent=new int[visit.length];
        visit[src]=true;
        Queue<Integer>q=new LinkedList<>();
        q.offer(src);
        while(!q.isEmpty()){
            int front=q.peek();
            q.poll();
            for(int i:adjList.get(front)){
                 if(visit[i] && i!=parent[front]){

                    return true;
                 }
                 else if(!visit[i]){ 
                     q.offer(i);
                     visit[i]=true;
                    parent[i]=front ;

                 }
            }
        }
        return false;


    }

    
    public static String cycleDetection(int[][] edges, int n, int m) {



        List<List<Integer>>adjList=new ArrayList<>();
        for(int i=0;i<=n;i++){
            adjList.add(new ArrayList<>());

        }
        for(int []i:edges){
            int u=i[0];
            int v=i[1];
            adjList.get(u).add(v);
            adjList.get(v).add(u);
        }
        Boolean [] visit=new Boolean[n+1];
        Arrays.fill(visit, false); // Initialize all nodes as unvisited
        for(int i=0;i<n;i++){
            if(!visit[i]){
                boolean ans=isCyclic(i,visit,adjList);
                if(ans){
                    return "Yes";
                }
            }
        }
        return "No";


        // Write your code here.
    }
     



    // dsf 
    public boolean isBSF(int src, ArrayList<ArrayList<Integer>> adj,Boolean []visit,Boolean[] adjVisit) {
        
        visit[src]=true;   
        adjVisit[src]=true;
        for(int i:adj.get(src)){
            if(!visit[i]){
                boolean ans=isBSF(i,adj,visit,adjVisit);
                if(ans){
                    return true;
                }
            }
            else if(adjVisit[i]){
                return true; 
                
            }
        }
        adjVisit[src]=false;
        return false;
        
        
        
        
        
    }

    // Function to detect cycle in a directed graph.
    public boolean isCyclic(int V, ArrayList<ArrayList<Integer>> adj) {


        Boolean[] visit=new Boolean[V];
        
        Boolean[] adjVisit=new Boolean[V];
        Arrays.fill(visit, false);
        Arrays.fill(adjVisit, false);
        
        for(int i=0;i<V;i++){
            if(!visit[i]){
                boolean ans=isBSF(i,adj,visit,adjVisit);
                if(ans){
                    return true;
                }
            }
        }
        return false;
        
        
        
        
        
        
        
        
        
        
        // code here
    }

    public boolean dfs(int i, ArrayList<ArrayList<Integer>>ls ,int destination,boolean[]visited) {


        if(i==destination){
            return true;
        }

        visited[i]=true;
        for(int neighbours:ls.get(i)){
            if(!visited[neighbours]){
                boolean ans=dfs(neighbours,ls,destination,visited);
                if(ans){
                    return true;
                }

            }

        }
        return false;


    }


    public boolean validPath(int n, int[][] edges, int source, int destination) {


        ArrayList<ArrayList<Integer>>ls=new ArrayList<>();
        for (int i = 0; i < n; i++) {
            ls.add(new ArrayList<>()); // Add an empty list for each node
        }
        for(int []i:edges){
            int u=i[0];
            int v=i[1];
            ls.get(u).add(v);

            ls.get(v).add(u);


        }
        if (source == destination) {
            return true;
        }

        boolean []visited=new boolean[n];
        
        return dfs(source,ls,destination,visited);
               
        
    }

    





    
}
