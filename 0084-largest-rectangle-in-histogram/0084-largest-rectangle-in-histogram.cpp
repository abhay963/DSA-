class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int n=heights.size();
        vector<int>pse(n),nse(n);

        for(int i=n-1;i>=0;i--){
          while(!st.empty() && heights[st.top()]>=heights[i])st.pop();

          if(st.empty())nse[i]=n;
          else nse[i]=st.top();
          st.push(i);
        }

        while(!st.empty())st.pop();

        for(int i=0;i<n;i++){
          while(!st.empty() && heights[st.top()]>=heights[i])st.pop();

          if(st.empty())pse[i]=-1;
          else pse[i]=st.top();
          st.push(i);
        }


        int maxi=INT_MIN;
        for(int i=0;i<heights.size();i++){
          maxi=max(maxi,heights[i]*(nse[i]-pse[i]-1));
        }

        return maxi;
    }
};