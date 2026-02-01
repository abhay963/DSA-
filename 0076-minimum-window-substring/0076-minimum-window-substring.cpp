class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
       
        int hash[256]={0};
        for(int i=0;i<t.size();i++)hash[t[i]]++;
         int i=0,j=0,cnt=0,minlength=INT_MAX,start=-1;
        while(j<s.size()){
            if(hash[s[j]]>0)cnt++;
            hash[s[j]]--;
            while(cnt==t.size()){
              if(minlength>j-i+1){
                minlength=j-i+1;
                start=i;
              }
              hash[s[i]]++;
              if(hash[s[i]]>0)cnt=cnt-1;
              i++;
            }
            j++;
        }
        if(start==-1)return "";
        else return s.substr(start,minlength);
    }
};