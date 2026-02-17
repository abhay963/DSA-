class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
     vector<int>ans;

     int n=matrix.size();
     int m=matrix[0].size();
     for(int i=0;i<n;i++){
      int mini=INT_MAX;
      int idx=-1;
      for(int j=0;j<m;j++){
        if(matrix[i][j]<mini){
          mini=matrix[i][j];
          idx=j;
        }
      
      }
bool islucky=false;
      for(int k=0;k<n;k++){
          if(matrix[k][idx]>mini){
            islucky=true;
            break;
          }
      }
      if(!islucky)ans.push_back(mini);
     }   
     return ans;
    }
};