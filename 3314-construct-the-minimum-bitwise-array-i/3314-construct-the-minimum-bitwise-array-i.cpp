class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans(nums.size(),-1);
      for(int i=0;i<nums.size();i++){
        int val=nums[i];
        for(int j=0;j<val;j++){
            if((j|j+1)==val){
              ans[i]=j;
              break;
            }
        }
       
      }
        return ans;
    }
};