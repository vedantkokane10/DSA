/*
An image is represented by a 2-D array of integers, each integer representing the pixel value of the image.
Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.
To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on.
Replace the color of all of the aforementioned pixels with the newColor.


Ex
Input: image = {{1,1,1},{1,1,0},{1,0,1}},
sr = 1, sc = 1, newColor = 2.
Output: {{2,2,2},{2,2,0},{2,0,1}}
Explanation: From the center of the image 
(with position (sr, sc) = (1, 1)), all 
pixels connected by a path of the same color
as the starting pixel are colored with the new 
color.Note the bottom corner is not colored 2, 
because it is not 4-directionally connected to 
the starting pixel.
*/


void dfs(int row,int col,vector<vector<int>>& image,vector<vector<bool>>& vis,int color){
    int n = image.size();
    int m = image[0].size();
    int oldColor = image[row][col];
    vis[row][col] = 1;
    image[row][col] = color;
    int dr[4] = {0,-1,0,1};
    int dc[4] = {-1,0,1,0};
    for(int i=0;i<4;i++){
        int nrow = row + dr[i];
        int ncol = col + dc[i];
        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m){
            if(image[nrow][ncol] == oldColor && !vis[nrow][ncol]){
                dfs(nrow,ncol,image,vis,color);
            }
        }
    } 
    
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    // Code here 
    int n = image.size();
    int m = image[0].size();
    vector<vector<bool>> vis(n,vector<bool>(m,0));
    dfs(sr,sc,image,vis,newColor);
    return image;
}
