// Function to detect cycle in an undirected graph.
bool bfs(int sourceNode,vector<int> adj[],vector<bool> &vis){
  queue<pair<int,int>> q1;
  vis[sourceNode] = 1;
  q1.push({sourceNode,sourceNode});
  while(!q1.empty()){
      int node = q1.front().first;
      int parent = q1.front().second;
      q1.pop();
      for(auto x:adj[node]){
          if(x != parent){
              if(!vis[x]){
                  vis[x] = 1;
                  q1.push({x,node});
              }
              else{
                  return 1;
              }
          }
      }
  }
  return 0;
}

bool isCycle(int V, vector<int> adj[]) {
  // Code here
  vector<bool> vis(V,0);
  for(int i=0;i<V;i++){
      if(!vis[i]){
          if(bfs(i,adj,vis) == 1){
              return 1;
          }
      }
  }
  return 0;
}
