class Solution {
public:
    int longestBalanced(string s) {
       int maxi=0;
        for(int i=0;i<s.size();i++){
           unordered_map<char,int>freq;
           for(int j=i;j<s.size();j++){
            freq[s[j]]++;
            bool check=true;
            int val=freq[s[j]];
            for(auto & it:freq){
                if(it.second!=val)check=false;
            }
            if(check)maxi=max(maxi,j-i+1);
           }
        }
        return maxi;
    }
};