package graphs.questionsStiver;

import java.util.ArrayList;

public class a {
    public static void main(String[] args) {
        
    }
    // no of province 


    static int province(ArrayList<ArrayList<Integer>>adj,int v){

        ArrayList<ArrayList<Integer>>adjLS=new ArrayList<ArrayList<Integer>>();
        for(int i=0;i<v;i++){
            adjLS.add(new ArrayList<Integer>());
        }

        // converting marix to arraylist
        // in graphs i and j work as btoh index and nodes
        // if  i is cooneted to j then j will must be connected to i
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(adj.get(i).get(j)==1 && i!=j){// if i==j when self connected node to itself
                    adjLS.get(i).add(j);
                    adjLS.get(j).add(i);
                    

                }
            }
        }
        int vis[]=new int[v];
        int cnt=0;
        for(int i=0;i<v;i++){
            if(vis[i]==0){
                cnt++;
                dfs(i,adjLS,vis);
            }
        }




    }



    
    
}
