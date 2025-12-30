class Solution {
public:
bool isvalid(vector<vector<int>>& grid,int row,int col){
  unordered_set<int>st;
  for(int i=row;i<row+3;i++){
    for(int j=col;j<col+3;j++){
      if(grid[i][j]<1 || grid[i][j]>9 || st.count(grid[i][j]))return false;
      else st.insert(grid[i][j]);
    }
  }

  int rowsum=grid[row][col]+grid[row][col+1]+grid[row][col+2];
  for(int i=0;i<3;i++){
    if(grid[row+i][col]+grid[row+i][col+1]+grid[row+i][col+2]!=rowsum)return false;

    if(grid[row][col+i]+grid[row+1][col+i]+grid[row+2][col+i]!=rowsum)return false;
  }


  if(grid[row][col]+grid[row+1][col+1]+grid[row+2][col+2]!=rowsum)return false;
  if(grid[row][col+2]+grid[row+1][col+1]+grid[row+2][col]!=rowsum)return false;

  return true;
}
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int cnt=0;
        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<=n-3;i++){
          for(int j=0;j<=m-3;j++){
            if(isvalid(grid,i,j))cnt++;
          }
        }
        return cnt;
    }
};