class Solution {
public:
int solve(int i,int j,vector<vector<int>>& grid){
  if(i==0 && j==0)return grid[0][0];
  if(i<0 ||j<0)return 1e5;
  int up=grid[i][j]+solve(i-1,j,grid);
  int left=grid[i][j]+solve(i,j-1,grid);
  return min(up,left);
}
    int minPathSum(vector<vector<int>>& grid) {
      int n=grid.size();
      int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
            if(i==0 && j==0)dp[i][j]=grid[i][j];
            else{
              int up=INT_MAX,left=INT_MAX;
              if(i>0)up=grid[i][j]+dp[i-1][j];
              if(j>0)left=grid[i][j]+dp[i][j-1];
              dp[i][j]=min(up,left);
            }
          }
        }
        return dp[n-1][m-1];
    }
};