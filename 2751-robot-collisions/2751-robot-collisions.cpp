class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size();
        vector<int>actualIndex(n);
        iota(actualIndex.begin(),actualIndex.end(),0);

        sort(actualIndex.begin(),actualIndex.end(),[&](int& a,int& b){
          return positions[a]<positions[b];
        });

        vector<int>result;
        stack<int>st;
        for(int& curridx:actualIndex){
          if(directions[curridx]=='R')st.push(curridx);
          else{
            while(!st.empty() && healths[curridx]>0){
              int top=st.top();
              st.pop();
              if(healths[top]>healths[curridx]){
                healths[top]-=1;
                healths[curridx]=0;
                st.push(top);
              }
              else if(healths[curridx]>healths[top]){
                healths[curridx]-=1;
                healths[top]=0;
              }
              else{
                healths[curridx]=0;
                healths[top]=0;
              }
            }
          }
        }

        for(int i=0;i<n;i++){
          if(healths[i]!=0)result.push_back(healths[i]);
        }
        return result;
    }
};