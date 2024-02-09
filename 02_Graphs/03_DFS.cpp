void dfs(int node, vector<int> adj[], vector<bool> &vis,vector<int> &ans){
    vis[node] = 1;
    ans.push_back(node);
    for(auto x : adj[node]){
        if(!vis[x]){
            dfs(x,adj,vis,ans);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    // Code here
    vector<bool>vis(V,0);
    vector<int> ans;
    dfs(0,adj,vis,ans);
    return ans;
}
