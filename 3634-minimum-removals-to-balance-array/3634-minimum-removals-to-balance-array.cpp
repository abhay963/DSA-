class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0,cnt=0;
        int maxi=0;
        
        for(int j=0;j<nums.size();j++){
          while(nums[j]>1LL * nums[i]* k){
            i++;
          }
          maxi=max(maxi,j-i+1);
        }
        int n=nums.size();
        return n-maxi;
       
    }
};