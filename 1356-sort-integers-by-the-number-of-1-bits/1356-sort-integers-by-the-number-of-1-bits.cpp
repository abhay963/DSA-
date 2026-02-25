class Solution {
public:
static bool cmp(pair<int,int>& a,pair<int,int>& b){
if(a.second!=b.second)return a.second<b.second;
  else return a.first<b.first;
}
    vector<int> sortByBits(vector<int>& arr) {
      vector<pair<int,int>>vec;
     for(int i=0;i<arr.size();i++){
        int cnt=__builtin_popcount(arr[i]);
    vec.push_back({arr[i],cnt});
     }

     sort(vec.begin(),vec.end(),cmp);
     vector<int>ans;
     for(auto& it:vec){
      ans.push_back(it.first);
     }
     return ans;
    }
};