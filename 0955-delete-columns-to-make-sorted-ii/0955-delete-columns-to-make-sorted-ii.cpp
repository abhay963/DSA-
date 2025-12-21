class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size();
        int m=strs[0].size();
        vector<bool>vis(n,false);
        int ans=0;

        for(int col=0;col<m;col++){
          bool deleted=false;
          for(int row=0;row<n-1;row++){
            if(!vis[row] && strs[row][col]>strs[row+1][col]){
              ans++;
              deleted=true;
              break;
            }
          }
          if(deleted)continue;

          for(int i=0;i<n-1;i++){
vis[i]=vis[i]| (strs[i][col]<strs[i+1][col]);
          }
        }
        return ans;
    }
};