class Solution {
public:
void dfs(int row,int col,vector<vector<int>>& vis,vector<vector<char>>& grid){
  vis[row][col]=1;
  int dr[4]={-1,0,1,0};
  int dc[4]={0,1,0,-1};
  for(int i=0;i<4;i++){
    int nrow=row+dr[i];
    int ncol=col+dc[i];
    if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size() && !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
      dfs(nrow,ncol,vis,grid);
    }
  }
}
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
            if(grid[i][j]=='1' && !vis[i][j]){
              cnt++;
              dfs(i,j,vis,grid);
            }
          }
        }
        return cnt;
    }
};