class Solution {
public:
bool check(int day,int row,int col,vector<vector<int>>& cells){
      vector<vector<int>>grid(row,vector<int>(col,1));
      for(int i=0;i<day;i++){
        int r=cells[i][0]-1;
        int c=cells[i][1]-1;
        grid[r][c]=0;
      }

vector<vector<bool>>vis(row,vector<bool>(col,false));
queue<pair<int,int>>q;
for(int i=0;i<col;i++){
  if(grid[0][i]==1){
    q.push({0,i});
    vis[0][i]=false;
  }
}
int dr[4]={-1,0,1,0};
int dc[4]={0,1,0,-1};
while(!q.empty()){
  auto top=q.front();
  q.pop();
  int r=top.first;
  int c=top.second;
  if(r==row-1)return true;
  for(int i=0;i<4;i++){
    int nrow=r+dr[i];
    int ncol=c+dc[i];
    if(nrow>=0 && nrow<row && ncol>=0 && ncol<col && !vis[nrow][ncol] && grid[nrow][ncol]==1){
      q.push({nrow,ncol});
      vis[nrow][ncol]=true;
    }
  }
}


return false;
}
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int ans=0;
        int low=0,high=cells.size()-1;
        while(low<=high){
          int mid=low+(high-low)/2;
          if(check(mid,row,col,cells)){
            ans=mid;
            low=mid+1;
          }
          else high=mid-1;
        }
        return ans;
    }
};