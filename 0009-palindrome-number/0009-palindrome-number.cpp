class Solution {
public:
    bool isPalindrome(int x) {
      string str=to_string(x);
   
      string org=str;
      reverse(str.begin(),str.end());
      return str==org;
       
    }
};