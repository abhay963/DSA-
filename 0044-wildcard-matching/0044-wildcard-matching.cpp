class Solution {
public:
bool solve(int i,int j,string& s,string& p,vector<vector<bool>>& dp){
  if(i==0 && j==0)return true;
  if(j==0 && i>0)return false;
  if(i==0  && j>0){
    for(int k=0;k<j;k++){
      if(p[k]!='*')return false;
    }
    return true;
  }
  if(dp[i][j]!=false)return dp[i][j];

  if(s[i-1]==p[j-1]|| p[j-1]=='?')return dp[i][j]= solve(i-1,j-1,s,p,dp);
  if(p[j-1]=='*')return dp[i][j]= solve(i-1,j,s,p,dp) || solve(i,j-1,s,p,dp);
  return dp[i][j]= false;
}


    bool isMatch(string s, string p) {
         int n=s.size();
        int m=p.size();
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
        vector<bool>prev(m+1,false);
        prev[0]=true;
       
        for(int j=1;j<=m;j++){
          bool fl=true;
            for(int k=1;k<=j;k++){

      if(p[k-1]!='*')fl= false;
      
        }
        prev[j]=fl;
        }

       

        for(int i=1;i<=n;i++){
          vector<bool>curr(m+1,false);
          for(int j=1;j<=m;j++){

            
  if(s[i-1]==p[j-1]|| p[j-1]=='?') curr[j]= prev[j-1];
 else if(p[j-1]=='*') curr[j]=prev[j]||curr[j-1]; 
   else curr[j]= false;
          }
          prev=curr;
        }
      return  prev[m];
    }
};