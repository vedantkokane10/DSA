 void bfs(int V,vector<int> adj[],vector<int> &ans){
    vector<int> vis(V);
    queue<int> q1;
    q1.push(0);
    vis[0] = 1;
    while(!q1.empty()){
        int node = q1.front();
        ans.push_back(node);
        q1.pop();
        for(auto x : adj[node]){
            if(!vis[x]){
                vis[x] = 1;
                q1.push(x);
            }
        }
    }
    }
    
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    // Code here
    vector<int> ans;
    bfs(V,adj,ans);
    return ans;
}
