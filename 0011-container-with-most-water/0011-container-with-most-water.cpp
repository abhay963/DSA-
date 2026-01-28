class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1,maxi=INT_MIN,mini=INT_MAX;
        while(i<j){
          int width=j-i;
          mini=min(height[j],height[i]);
          maxi=max(maxi,width*mini);
          if(height[i]<height[j])i++;
          else j--;
        }
        return maxi;
    }
};