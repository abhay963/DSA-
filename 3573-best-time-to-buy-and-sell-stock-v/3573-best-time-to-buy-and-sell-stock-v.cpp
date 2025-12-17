class Solution {
public:
long long solve(int idx,int state,int k,vector<int>& prices,
vector<vector<vector<long long>>>& dp){
  if(idx>=prices.size()){
    if(state==0)return 0;
    else return INT_MIN;
  }
  if(dp[idx][state][k]!=-1)return dp[idx][state][k];
long long take=INT_MIN;
long long nottake;
nottake=solve(idx+1,state,k,prices,dp);
 if(k>0){
  if(state==1){
    take=prices[idx]+solve(idx+1,0,k-1,prices,dp);
  }
  else if(state==2){
    take=-prices[idx]+solve(idx+1,0,k-1,prices,dp);
  }
  else{
    take=max(
     ( -prices[idx]+solve(idx+1,1,k,prices,dp)),
      (prices[idx]+solve(idx+1,2,k,prices,dp))
    );
  }
 }

 return dp[idx][state][k]=max(take,nottake);
}
    long long maximumProfit(vector<int>& prices, int k) {
          int n=prices.size();
          vector<vector<vector<long long>>>dp(n,
          vector<vector<long long>>(3,
          vector<long long>(k+1,-1)));
        return solve(0,0,k,prices,dp);
    }
};