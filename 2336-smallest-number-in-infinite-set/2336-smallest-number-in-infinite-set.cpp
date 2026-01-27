class SmallestInfiniteSet {
public:
priority_queue<int,vector<int>,greater<int>>pq;
unordered_set<int>st;

    SmallestInfiniteSet() {
        for(int i=1;i<=1000;i++){
          st.insert(i);
          pq.push(i);
        }
    }
    
    int popSmallest() {
      int top=pq.top();
        pq.pop();
        if(st.find(top)!=st.end())st.erase(top);
        return top;
    }
    
    void addBack(int num) {
        if(st.find(num)==st.end()){
          pq.push(num);
          st.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */