class Solution {
public:
const int mod=1e9+7;

long long power(long long a,long long b){
  if(b==0)return 1;

  long long res=1;
  while(b!=0){
    if(b%2==1)res=(res*a)%mod;
    a=(a*a)%mod;
    b=b/2;
  }
  return res;
}
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
       int n=nums.size();
       int blocksize=ceil(sqrt(n));

       unordered_map<int,vector<vector<int>>>smallK;

       for(auto & it:queries){
        int l=it[0];
        int r=it[1];
        int k=it[2];
        int v=it[3];
        if(k>=blocksize){

          int idx=l;
          while(idx<=r){
            nums[idx]=(1ll*nums[idx]*v)%mod;
            idx+=k;
          }
        }
        else smallK[k].push_back(it);
       }


       for(auto& [k,query]:smallK){
        vector<long long>diff(n,1);
        for(auto& it:query){
          int l=it[0];
          int r=it[1];
          int v=it[3];
          diff[l]=(diff[l]*v)%mod;
          int steps=(r-l)/k;
          int next=l+(steps+1)*k;
          if(next<n){
            diff[next]=(diff[next]*power(v,mod-2))%mod;
          }

        
        }
          for(int i=0;i<n;i++){
            if(i-k>=0){
              diff[i]=(1ll* diff[i]*diff[i-k])%mod;
            }
          }
          for(int i=0;i<n;i++){
            nums[i]=(nums[i]*diff[i]*1ll)%mod;
          }
       }

       int xr=nums[0];
       for(int i=1;i<n;i++){
        xr=xr^nums[i];
       }
       return xr;
    }
};