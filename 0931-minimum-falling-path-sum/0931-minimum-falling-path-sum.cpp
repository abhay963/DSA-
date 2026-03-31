class Solution {
public:
int n,m;






int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
  
  if(i<0 ||i>=n||j<0||j>=m)return 1e5;
  if(i==n-1)return grid[i][j];
  if(dp[i][j]!=-1)return dp[i][j];
  int u=grid[i][j]+solve(i+1,j,grid,dp);
  int r=grid[i][j]+solve(i+1,j-1,grid,dp);
  int rc=grid[i][j]+solve(i+1,j+1,grid,dp);
  
  return dp[i][j]=min(u,min(r,rc));
}
    int minFallingPathSum(vector<vector<int>>& grid) {
      
         n=grid.size();
         m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
      for(int i=m-1;i>=0;i--){
        dp[n-1][i]=grid[n-1][i];
      }

      for(int i=n-2;i>=0;i--){
        for(int j=m-1;j>=0;j--){
int u=1e5,r=1e5,rc=1e5;
 u=grid[i][j]+dp[i+1][j];
 if(j-1>=0)r=grid[i][j]+dp[i+1][j-1];
  if(j+1<m)rc=grid[i][j]+dp[i+1][j+1];
  
   dp[i][j]=min(u,min(r,rc));

        }
      }
     int ans=INT_MAX;
     for(int i=0;i<m;i++)ans=min(ans,dp[0][i]);
     return ans;   
    }
};