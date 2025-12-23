class Solution {
public:
int nextvalid(int idx,vector<vector<int>>& events){
  int val=events[idx][1];
  int ans=events.size();
  int low=idx+1;
  int high=events.size()-1;
  while(low<=high){
    int mid=low+(high-low)/2;
    if(events[mid][0]>val){
      ans=mid;
      high=mid-1;
    }
    else low=mid+1;
  }
  return ans;
  
}
int solve(int idx,int cnt,vector<vector<int>>& events,vector<vector<int>>& dp){
if(cnt==2)return 0;
  if(idx==events.size())return 0;
  if(dp[idx][cnt]!=-1)return dp[idx][cnt];
  int nottake=solve(idx+1,cnt,events,dp);
  int take=events[idx][2]+solve(nextvalid(idx,events),cnt+1,events,dp);
  return dp[idx][cnt]= max(take,nottake);
}
    int maxTwoEvents(vector<vector<int>>& events) {
        int maxi=0;
        int n=events.size();
        vector<vector<int>>dp(n,vector<int>(3,-1));
        sort(events.begin(),events.end());
       return solve(0,0,events,dp);
    }
};