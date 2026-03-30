class Solution {
public:
    bool checkStrings(string s1, string s2) {
      if(s1.size()!=s2.size())return false;
        int even[26]={0};
        int odd[26]={0};
        for(int i=0;i<s1.size();i++){
            if(i%2==0){
              even[s1[i]-'a']++;
              even[s2[i]-'a']--;
            }
            else{
              odd[s1[i]-'a']++;
              odd[s2[i]-'a']--;
            }
        }
        for(int i=0;i<26;i++){
          if(even[i]!=0 || odd[i]!=0)return false;
        }
        return true;
    }
};