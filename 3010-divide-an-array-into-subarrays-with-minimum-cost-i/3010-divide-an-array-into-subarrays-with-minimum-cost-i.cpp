class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int ans=nums[0];
        vector<int>res(nums.begin()+1,nums.end());
        sort(res.begin(),res.end());
        ans+=res[0];
        ans+=res[1];
        return ans;
    }
};