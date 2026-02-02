class Solution {
public:
int solve(vector<int>& nums,int k){
  
  int i=0,j=0,sum=0,cnt=0;
  while(j<nums.size()){
    sum+=nums[j]%2;
    while(sum>k){
      sum-=nums[i]%2;
      i++;
    }
    cnt+=(j-i+1);
    j++;
  }
  return cnt;
}
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};