class Solution {
public:
const int mod=1e9+7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(auto& it:queries){
          int l=it[0];
          int r=it[1];
          int k=it[2];
          int v=it[3];
          while(l<=r){
            nums[l]=(1LL *nums[l]*v)%mod;
            l+=k;
          }
        }

        int xr=nums[0];
        for(int i=1;i<nums.size();i++){
          xr=xr^nums[i];
        }
        return xr;
    }
};