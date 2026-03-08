class Solution {
public:
string solve(int idx,int n,string temp,unordered_set<string>& st){
  if(idx==n){
    if(st.find(temp)==st.end())return temp;
    else return "";
  }

  string left=solve(idx+1,n,temp+"0",st);
  if(left!="")return left;
  string right=solve(idx+1,n,temp+"1",st);
  if(right!="")return right;

  return "";

}
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums[0].size();
        unordered_set<string>st;
        for(string it:nums)st.insert(it);
        return solve(0,n,"",st);
    }
};