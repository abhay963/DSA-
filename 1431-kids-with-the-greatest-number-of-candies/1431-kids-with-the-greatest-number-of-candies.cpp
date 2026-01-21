class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool>ans;
        int maxi=*max_element(candies.begin(),candies.end());
        for(int i=0;i<candies.size();i++){
          int val=candies[i]+extraCandies;
          if(val>=maxi)ans.push_back(true);
          else ans.push_back(false);
        }
        return ans;
    }
};