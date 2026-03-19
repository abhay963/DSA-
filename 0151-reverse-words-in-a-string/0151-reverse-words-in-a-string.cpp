class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        string ans="";
        reverse(s.begin(),s.end());
        for(int i=0;i<s.size();i++){
          string word="";
          while(i<n && s[i]!=' '){
            word+=s[i];
            i++;
          }
         
          if(word.size()>0){
 reverse(word.begin(),word.end());
            ans+=(' '+ word);
          }
        }
        return ans.substr(1);
    }
};