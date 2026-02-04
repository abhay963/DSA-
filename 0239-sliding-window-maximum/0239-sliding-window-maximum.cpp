class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        int i=0,j=0;
        multiset<int>st;
        while(j<nums.size()){
          st.insert(nums[j]);
          if(j-i+1>k){
            st.erase(st.find(nums[i]));
            i++;
          }

          if(j-i+1==k){
            int el=*st.rbegin();
            ans.push_back(el);
          }
          j++;

        }
return ans;
    }
};