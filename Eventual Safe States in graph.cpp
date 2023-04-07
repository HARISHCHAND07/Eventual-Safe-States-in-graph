
class Solution {
    private:
     bool dfs(int node,int vis[],int path[],vector<int> adj[],int check[])
     {
         vis[node]=1;
         path[node]=1;check[node]=0;
         for(auto it:adj[node])
         {
             if(!vis[it]){
                 if(dfs(it,vis,path,adj,check)==true){
                     check[node]=0;
                     return true;}
             }else if(path[it]){
                 check[node]=0;
                 return true;
          }
             
         }check[node]=1;
         path[node]=0;
         return false;
     }
  public:
    // Function to detect cycle in a directed graph.
    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
        int vis[V]={0};int check[V]={0};
        vector<int> safestate;
        int path[V]={0};
        for(int i=0;i<V;i++){
           if(!vis[i]){ 
               dfs(i,vis,path,adj,check);
        }}
        for(int i=0;i<V;i++){
            if(check[i]==1){
                safestate.push_back(i);
            }
        }return safestate;
    }
};