bool dfs(int node,int parent,vector<int> adj[],vector<bool> &vis){
    vis[node] = 1;
    vis[parent] = 1;
    for(auto x:adj[node]){
        if(x != parent){
            if(!vis[x]){
                if(dfs(x,node,adj,vis) == 1){
                    return 1;
                }
            }
            else{
                return 1;
            }
        }
    }
    return 0;
}

bool isCycle(int V, vector<int> adj[]) {
    // Code here
    vector<bool> vis(V,0);
    // We are checking for each node becasue there can non-connected graph components present
    for(int i=0;i<V;i++){
        if(!vis[i]){
            if(dfs(i,i,adj,vis) == 1){
                return 1;
            }
        }
    }
    return 0;
}
