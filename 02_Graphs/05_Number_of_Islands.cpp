/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.


*/

void bfs(int row,int col, vector<vector<char>>& grid,vector<vector<bool>>& vis){
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int,int>> q1;
    vis[row][col] = 1;
    q1.push({row,col});

    // left, up, right, down
    int dr[4] = {0,-1,0,1};
    int dc[4] = {-1,0,1,0};
    while(!q1.empty()){
        int row = q1.front().first;
        int col = q1.front().second;
        q1.pop();
        for(int i=0;i<4;i++){
            int nrow = row + dr[i];
            int ncol = col + dc[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m){
                if(grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    q1.push({nrow,ncol});
                }
            }
        }
    }

}
int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int cnt = 0;
    vector<vector<bool>>vis(n,vector<bool>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == '1' && !vis[i][j]){
                cnt++;
                bfs(i,j,grid,vis);
            }
        }
    }
    return cnt;
}
