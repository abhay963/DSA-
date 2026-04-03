class Solution {
public:
int solve(int idx,int target,vector<int>& coins,
vector<vector<int>>& dp){
 
  if(idx==0){
    return (target%coins[idx]==0);
  }
  if(dp[idx][target]!=-1)return dp[idx][target];


  int nottake=solve(idx-1,target,coins,dp);
  int take=0;
  if(coins[idx]<=target)take=solve(idx,target-coins[idx],coins,dp);
  return dp[idx][target]=take+nottake;
}
    int change(int amount, vector<int>& coins) {
      int n=coins.size();
     vector<int>prev(amount+1,0);
     for(int i=0;i<=amount;i++){
      if(i%coins[0]==0)prev[i]=1;
     }

     for(int i=1;i<n;i++){
      vector<int>curr(amount+1,0);
for(int target=0;target<=amount;target++){
 long  nottake=prev[target];
  long take=0;
  if(coins[i]<=target)take=curr[target-coins[i]];
  curr[target]=take+nottake;
}
prev=curr;
     }
     return prev[amount];
    }
};