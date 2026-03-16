class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
      if(grid[0][0]==1)return -1;
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;

        pq.push({1,{0,0}});
        int n=grid.size();
        vector<vector<int>>vis(n,vector<int>(n,0));
        int dr[8]={-1,-1,0,1,1,1,0,-1};
        int dc[8]={0,1,1,1,0,-1,-1,-1};
        while(!pq.empty()){
          auto top=pq.top();
          pq.pop();
          int step=top.first;
          int row=top.second.first;
          int col=top.second.second;
          if(row==n-1 && col==n-1)return step;
          for(int i=0;i<8;i++){
            int nrow=dr[i]+row;
            int ncol=dc[i]+col;
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==0 && !vis[nrow][ncol]){
              pq.push({step+1,{nrow,ncol}});
              vis[nrow][ncol]=1;
            } 
          }
        }
        return -1;
    }
};