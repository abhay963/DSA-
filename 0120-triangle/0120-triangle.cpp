class Solution {
public:
int n;
int solve(int i,int j,vector<vector<int>>& triangle){
  if(i==n-1)return triangle[n-1][j];
 if(i>=n ||i<0 )return 1e8;
 int d=triangle[i][j]+solve(i+1,j,triangle);
 int dg=triangle[i][j]+solve(i+1,j+1,triangle);
 return min(d,dg);
  
}
    int minimumTotal(vector<vector<int>>& triangle) {
      n=triangle.size();
       vector<int>prev(n,0);
       for(int i=n-1;i>=0;i--){
        prev[i]=triangle[n-1][i];
       }


       for(int i=n-2;i>=0;i--){
        vector<int>curr(n,0);
        for(int j=i;j>=0;j--){
          int d=1e8,dr=1e8;
          d=triangle[i][j]+prev[j];
          dr=triangle[i][j]+prev[j+1];
          curr[j]=min(d,dr);
        }
        prev=curr;
       }
       return prev[0];
    }
};