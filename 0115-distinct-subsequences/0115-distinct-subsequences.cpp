class Solution {
public:
int solve(int i,int j,string& s,string& t,
vector<vector<int>>& dp){
  if(j<0)return 1;
  if(i<0)return 0;
if(dp[i][j]!=-1)return dp[i][j];
  if(s[i]==t[j]){
    return dp[i][j]= solve(i-1,j-1,s,t,dp)+solve(i-1,j,s,t,dp);
  }

  else return dp[i][j]=solve(i-1,j,s,t,dp);
}
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        // vector<vector<unsigned long long>>dp(n+1,vector<unsigned long long>(m+1,0));
        vector<unsigned long long>prev(m+1,0);
       prev[0]=1;
        for(int i=1;i<=n;i++){
          vector<unsigned long long>curr(m+1,0);
          curr[0]=1;
          for(int j=1;j<=m;j++){
            long long take=0,nottake=0;
if(s[i-1]==t[j-1]){
  take=prev[j-1]+prev[j];
  }

  else nottake=curr[j]=prev[j];

  curr[j]=take+nottake;

          }
          prev=curr;
        }
     return prev[m];
    }
};