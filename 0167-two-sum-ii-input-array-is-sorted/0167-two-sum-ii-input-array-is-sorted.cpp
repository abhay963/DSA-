class Solution {
public:
int bs(int target,int low,int high,vector<int>& nums){
  while(low<=high){
    int mid=low+(high-low)/2;
    if(nums[mid]==target)return mid;
    if(nums[mid]>target){
high=mid-1;
    }
    else{
low=mid+1;
    }
  }
  return -1;

}
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i=0;i<numbers.size();i++){
          int num=numbers[i];
          int need=target-num;
          int idx=bs(need,i+1,numbers.size()-1,numbers);
          if(idx!=-1)return {i+1,idx+1};
        }
        return {};
    }
};