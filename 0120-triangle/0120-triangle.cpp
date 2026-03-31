class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=n-1;i>=0;i--){
          dp[n-1][i]=triangle[n-1][i];
        }

        for(int i=n-2;i>=0;i--){
          for(int j=i;j>=0;j--){
            int dr=1e8,d=1e8;
            d=triangle[i][j]+dp[i+1][j];
            dr=triangle[i][j]+dp[i+1][j+1];
            dp[i][j]=min(d,dr);
          }
        }
        return dp[0][0];
    }

};