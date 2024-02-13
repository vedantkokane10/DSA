/*
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
The distance between two adjacent cells is 1.

Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]
*/

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> ans(n,vector<int>(m,0));
    vector<vector<int>> vis(n,vector<int>(m,0));
    queue<pair<pair<int,int>,int>> q1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j] == 0){
                vis[i][j] = 1;
                q1.push({{i,j},0});
            }
        }
    }
  
  int dr[4] = {0,-1,0,1};
  int dc[4] = {-1,0,1,0};
    
  while(!q1.empty()){
        int row = q1.front().first.first;
        int col = q1.front().first.second;
        int dist = q1.front().second;
        ans[row][col] = dist;
        q1.pop();
        for(int i=0;i<4;i++){
            int nrow = row + dr[i];
            int ncol = col + dc[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m){
                if(vis[nrow][ncol] == 0){
                    vis[nrow][ncol] = 1;
                    q1.push({{nrow,ncol},dist+1});
                }
            }
        }
    }
    return ans;
}
