class Solution {
public:
    int beautySum(string s) {
        int ans=0;
        
        for(int i=0;i<s.size();i++){
            vector<int>freq(26,0);
            for(int j=i;j<s.size();j++){
              int maxi=0,mini=INT_MAX;
              freq[s[j]-'a']++;
              for(int k=0;k<26;k++){
                maxi=max(maxi,freq[k]);
                if(freq[k]>0){
                mini=min(mini,freq[k]);
                }
              }
              ans+=(maxi-mini);
            }
        }
        return ans;
    }
};