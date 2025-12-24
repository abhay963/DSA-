class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int total=0;
        for(int it:apple)total+=it;
        sort(capacity.begin(),capacity.end());
        int n=capacity.size();
        int cnt=0;
        for(int i=n-1;i>=0;i--){
          total-=capacity[i];
          cnt++;
          if(total<=0)break;
        }
        return cnt;
    }
};