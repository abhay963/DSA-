class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n=nums.size();
        int k=n/2;
        unordered_map<int,int>mp;
        for(int it:nums)mp[it]++;
        for(auto& it:mp){
          if(it.second==k)return it.first;
        }
        return -1;
    }
};