/*
Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there is a path from u to v or v to u.
Your task is to find the number of provinces.
Note: A province is a group of directly or indirectly connected cities and no other cities outside of the group.

Ex - 
1     2
 \ 
   3
Ans = 2

Ex - 
1 - 2
Ans = 1
*/


void dfs(int node, vector<int> adj[], vector<bool> &vis){
    vis[node] = 1;
    for(auto x : adj[node]){
        if(!vis[x]){
            dfs(x,adj,vis);
        }
    }
}
int numProvinces(vector<vector<int>> adjMatrix, int V) {
    // code here
    vector<int> adj[V];
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(adjMatrix[i][j] == 1 && i != j){
                 adj[i].push_back(j);
                 adj[j].push_back(i);   
            }
        }
    }
    vector<bool> vis(V);
    int cnt = 0;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            dfs(i,adj,vis);
            cnt++;
        }
    }
    return cnt;
}
