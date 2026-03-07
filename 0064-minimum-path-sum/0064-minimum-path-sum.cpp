class Solution {
public:
int solve(int i,int j,vector<vector<int>>& grid){
  if(i==0 && j==0)return grid[0][0];
  if(i<0 ||j<0)return 1e5;
  int up=grid[i][j]+solve(i-1,j,grid);
  int left=grid[i][j]+solve(i,j-1,grid);
  return min(up,left);
}
    int minPathSum(vector<vector<int>>& grid) {
      int n=grid.size();
      int m=grid[0].size();
       vector<int>prev(m,0);
        for(int i=0;i<n;i++){
          vector<int>temp(m,0);
          for(int j=0;j<m;j++){
            if(i==0 && j==0)temp[0]=grid[i][j];
            else{
              int up=INT_MAX,left=INT_MAX;
              if(i>0)up=grid[i][j]+prev[j];
              if(j>0)left=grid[i][j]+temp[j-1];
              temp[j]=min(up,left);
            }
          }
          prev=temp;
        }
        return prev[m-1];
    }
};