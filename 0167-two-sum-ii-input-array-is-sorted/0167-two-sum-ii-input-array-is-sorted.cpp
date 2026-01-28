class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int>mp;
        for(int i=0;i<numbers.size();i++){
          mp[numbers[i]]=i;
        }


        for(int i=0;i<numbers.size();i++){
          int num=numbers[i];
          int need=target-numbers[i];
          if(mp.find(need)!=mp.end()){
            return {i+1,mp[need]+1};
          }
        }
        return {};
    }
};