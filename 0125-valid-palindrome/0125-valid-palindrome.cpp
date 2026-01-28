class Solution {
public:
bool check(string str){
  int i=0,j=str.size()-1;
  while(i<=j){
    if(str[i]!=str[j])return false;
    i++;
    j--;
  }
  return true;
}
    bool isPalindrome(string s) {
        if(s.size()==0)return true;

        string ans="";
        for(int i=0;i<s.size();i++){
          if(isalnum(s[i])){
            ans+=tolower(s[i]);
          }
        }


        return check(ans);
    }
};