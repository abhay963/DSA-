class Solution {
public:
int histogram(vector<int>& arr){
  int n=arr.size();
  vector<int>pse(n),nse(n);

  stack<int>st;
for(int i=n-1;i>=0;i--){
  while(!st.empty() && arr[st.top()]>=arr[i]){
    st.pop();
  }
  if(!st.empty())nse[i]=st.top();
  else nse[i]=n;
  st.push(i);
}

while(!st.empty())st.pop();

for(int i=0;i<n;i++){
  while(!st.empty() && arr[st.top()]>=arr[i]){
    st.pop();
  }
if(!st.empty())pse[i]=st.top();
else pse[i]=-1;

st.push(i);
}

int maxi=0;
for(int i=0;i<n;i++){
  maxi=max(maxi,(arr[i]* (nse[i]-pse[i]-1)));
}
return maxi;

}
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>area(m,0);
        int ans=-1;
        for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
            if(matrix[i][j]=='1')
              area[j]+=(matrix[i][j]-'0');
              else area[j]=0;
             

          }
           int findmaxarea=histogram(area);
    ans=max(ans,findmaxarea);
        }
        return ans;
    }
};