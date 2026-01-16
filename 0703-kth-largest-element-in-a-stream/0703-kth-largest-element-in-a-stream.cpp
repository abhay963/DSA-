class KthLargest {
public:
int K;
priority_queue<int,vector<int>,greater<int>>minheap;
    KthLargest(int k, vector<int>& nums) {
      this->K=k;
      for(int it:nums)minheap.push(it);
        while(minheap.size()>k)minheap.pop();
      
    }
    
    int add(int val) {
        minheap.push(val);
        while(minheap.size()>K)minheap.pop();
        return minheap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */