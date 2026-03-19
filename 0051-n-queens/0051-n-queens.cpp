class Solution {
public:
vector<vector<string>>ans;
bool issafe(int row,int col,vector<string>& board,int n){
  int r=row,c=col;
  while(r>=0 && c>=0){
    if(board[r][c]=='Q')return false;
    r--;
    c--;
  }

  r=row;
  c=col;
  while(c>=0){
    if(board[r][c]=='Q')return false;
    c--;
  }

r=row;
c=col;

  while(r<n && c>=0){
    if(board[r][c]=='Q')return false;
    r++;
    c--;
  }

  return true;
}
void solve(int col,int n,vector<string>& board){
  if(col==n){
    ans.push_back(board);
    return;
  }

  for(int row=0;row<n;row++){
    if(issafe(row,col,board,n)){
      board[row][col]='Q';
      solve(col+1,n,board);
      board[row][col]='.';
    }
  }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        solve(0,n,board);
        return ans;
    }
};