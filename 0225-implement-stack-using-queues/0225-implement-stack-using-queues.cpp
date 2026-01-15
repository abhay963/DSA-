class MyStack {
    queue<int>q;
public:
    MyStack() {
      
    }
    
    void push(int x) {
        q.push(x);
        for(int i=1;i<q.size();i++){
          q.push(q.front());
          q.pop();
        }
    }
    
    int pop() {
      int el=-1;
      if(q.size()>0){
        el=q.front();
        q.pop();
      }
       return el;
    }
    
    int top() {
        if(!q.empty())return q.front();
        else return -1;
    }
    
    bool empty() {
        return q.empty()==true;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */