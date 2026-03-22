class Solution {
public:
bool solve(int row,int col,int n,int m,vector<vector<int>>& grid,int expval){
  if(row<0 || row>=n || col<0 || col>=m || grid[row][col]!=expval)return false;
if(expval==n*n-1)return true;
  int dr[8]={-2,-1,1,2,2,1,-1,-2};
  int dc[8]={1,2,2,1,-1,-2,-2,-1};

  for(int i=0;i<8;i++){
      int nrow=row+dr[i];
      int ncol=col+dc[i];
      if(solve(nrow,ncol,n,m,grid,expval+1)==true)return true;
  }
  return false;
}
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        return solve(0,0,n,m,grid,0);
    }
};