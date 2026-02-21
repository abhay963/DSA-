class Solution {
public:
int cnt=0;
bool check(string& s,int start,int end){
  while(start<=end){
    if(s[start]!=s[end])return false;
    start++;
    end--;
  }
return true;
}
void solve(int start,string& s){
  if(start==s.size())return;
  for(int end=start;end<s.size();end++){
    if(check(s,start,end))cnt++;
  }
  solve(start+1,s);
}
    int countSubstrings(string s) {
        solve(0,s);
        return cnt;
    }
};