class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            if(mp[num].size()==2){
              int j=mp[num][0];
              int k=mp[num][1];
              int val=abs(i-j)+abs(j-k)+abs(i-k);
              ans=min(ans,val);
              mp[num].erase(mp[num].begin());
              mp[num].push_back(i);
            }
            else {
              mp[num].push_back(i);
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};