class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int mini=INT_MAX;
        for(int i=0;i<nums.size();i++){
          if(nums[i]==1){
            for(int j=0;j<nums.size();j++){
              if(nums[j]==2){
                mini=min(mini,abs(i-j));
              }
            }
          }
        }
        if(mini==INT_MAX)return -1;
        return mini;
    }
};