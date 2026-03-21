class Solution {
public:
bool issafe(int row,int col,char ch,vector<vector<char>>& board){

  for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
      if(board[row][j]==ch)return false;
      if(board[j][col]==ch)return false;
      int boxrow=3*(row/3)+i/3;
      int boxcol=3*(col/3)+i%3;
      if(board[boxrow][boxcol]==ch)return false;
    }
  }
  return true;
}
bool solve(vector<vector<char>>& board){
int n=board.size();
int m=board[0].size();
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(board[i][j]=='.'){
        for(char ch='1';ch<='9';ch++){
          if(issafe(i,j,ch,board))
          {
 board[i][j]=ch;
          if(solve(board)==true)return true;
          board[i][j]='.';
          }
         
        }
  return false;
      }
    
    }
  }
  return true;
}
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};