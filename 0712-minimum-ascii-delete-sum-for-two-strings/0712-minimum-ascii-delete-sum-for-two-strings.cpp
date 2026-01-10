class Solution {
public:
int n,m;
vector<vector<int>>dp;
int solve(int i,int j,string& s1,string& s2)
{
  if(i>=n && j>=m)return 0;
 
  if(i>=n)return s2[j]+ solve(i,j+1,s1,s2);
  if(j>=m)return s1[i]+solve(i+1,j,s1,s2);
 if(dp[i][j]!=-1)return dp[i][j];
  if(s1[i]==s2[j]) return solve(i+1,j+1,s1,s2);
  int d1=s1[i]+solve(i+1,j,s1,s2);
  int d2=s2[j]+solve(i,j+1,s1,s2);
  return dp[i][j]=min(d1,d2);
}    int minimumDeleteSum(string s1, string s2) {
        n=s1.size();
        m=s2.size();
dp.assign(n,vector<int>(m,-1));
        return solve(0,0,s1,s2);
    }
};