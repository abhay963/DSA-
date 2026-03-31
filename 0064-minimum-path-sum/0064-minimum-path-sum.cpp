class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        dp[0][0]=grid[0][0];
        for(int i=1;i<m;i++)dp[0][i]=grid[0][i]+dp[0][i-1];
        for(int i=1;i<n;i++){
          for(int j=0;j<m;j++){
            int down=1e8,right=1e8;
            if(i-1>=0)down=grid[i][j]+dp[i-1][j];
            if(j-1>=0)right=grid[i][j]+dp[i][j-1];
            dp[i][j]=min(down,right);
          }
        }
        return dp[n-1][m-1];
    }
};