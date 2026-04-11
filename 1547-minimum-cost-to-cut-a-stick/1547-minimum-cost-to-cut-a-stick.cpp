class Solution {
public:
long long solve(long long i,long long j,vector<int>& cuts,vector<vector<int>>& dp){
  if(i>j)return 0;
  if(dp[i][j]!=-1)return dp[i][j];
  long long mini=INT_MAX;
  for(int k=i;k<=j;k++){
    long long cost=(long long)cuts[j+1]-cuts[i-1]+solve(i,k-1,cuts,dp)+solve(k+1,j,cuts,dp);
    mini=min(mini,cost);
  }
  return dp[i][j]= mini;
}
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        vector<vector<int>>dp(cuts.size(),vector<int>(cuts.size(),-1));
        return (int)solve(1,cuts.size()-2,cuts,dp);
    }
};