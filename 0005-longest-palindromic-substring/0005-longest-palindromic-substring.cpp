class Solution {
public:
vector<vector<char>>dp;
bool check(int i,int j,string& str){
  if(i>=j)return true;
 if(dp[i][j]!=-1)return dp[i][j];
 if(str[i]==str[j] && check(i+1,j-1,str)){
  return dp[i][j]=true;
 }
 else return dp[i][j]=false;
}
    string longestPalindrome(string s) {
      if(s.size()<=1)return s;
      int n=s.size();
       dp.assign(n,vector<char>(n,-1));
       int maxlen=-1,start=-1;
       for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
          if(check(i,j,s)){
            int len=j-i+1;
            if(len>maxlen){
              maxlen=len;
              start=i;
            }
          }
        }
       }
       return s.substr(start,maxlen);
    }
};