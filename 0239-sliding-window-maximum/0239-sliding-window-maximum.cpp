class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        int i=0,j=0;
        multiset<int>st;
        while(j<nums.size()){
          st.insert(nums[j]);
          if(j-i+1>k){
              st.erase(nums[i]);
              i++;
          }

          if(j-i+1==k){
            ans.push_back(*st.rbegin());
          }
          j++;
        }

        return ans;
    }
};