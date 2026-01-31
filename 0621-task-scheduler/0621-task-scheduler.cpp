class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int time=0;
        priority_queue<int>pq;
        vector<int>mp(26,0);
        for(char ch:tasks)mp[ch-'A']++;
    for(int i=0;i<26;i++){
      if(mp[i]>0)pq.push(mp[i]);
    }

    while(!pq.empty()){
      vector<int>temp;
      if(!pq.empty()){
        for(int i=0;i<=n&& !pq.empty();i++){
          int top=pq.top();
          pq.pop();
          top--;
          temp.push_back(top);
        }
      }
      for(int f:temp){
        if(f>0)pq.push(f);
      }

      if(pq.empty())time+=temp.size();
      else time+=(n+1);
    }
    return time;
    }
};