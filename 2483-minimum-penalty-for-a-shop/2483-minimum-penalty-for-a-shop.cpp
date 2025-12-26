class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        vector<int>pref(n+1);
        vector<int>suf(n+1);
        pref[0]=0;
        suf[n]=0;
        for(int i=1;i<=n;i++){
            if(customers[i-1]=='N'){
              pref[i]=1+pref[i-1];
            }
            else pref[i]=pref[i-1];
        }

        for(int i=n-1;i>=0;i--){
             if(customers[i]=='Y'){
              suf[i]=1+suf[i+1];
            }
            else suf[i]=suf[i+1];
        }
        


        int ans=INT_MAX,mini=INT_MAX;

        for(int i=0;i<=n;i++){
          int total=pref[i]+suf[i];
          if(total<mini){
            mini=total;
            ans=i;
          }
        }

          return ans;
        
    }
};