class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int  cnt=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
          int sum=0;
          for(int j=0;j<m;j++){
            if(i>0){
              grid[i][j]+=grid[i-1][j];
            }
            sum+=grid[i][j];
            if(sum<=k)cnt++;
          }
        }
        return cnt;
    }
};