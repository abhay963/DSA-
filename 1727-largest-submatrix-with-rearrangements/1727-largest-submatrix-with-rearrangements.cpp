class Solution {
public:
int solve(vector<int>& arr){
  int maxi=0;
  sort(arr.begin(),arr.end(),greater<int>());
  for(int i=0;i<arr.size();i++){
    int area=arr[i]*(i+1);
    maxi=max(maxi,area);
  }
  return maxi;
}
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxi=0;
        for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
if(i>0){
  if(matrix[i][j]==1)
  matrix[i][j]+=matrix[i-1][j];
}
          }
          vector<int>temp=matrix[i];
          maxi=max(maxi,solve(temp));
        }
        return maxi;
    }
};