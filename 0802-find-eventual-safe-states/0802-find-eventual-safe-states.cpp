class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>ans;
        int v=graph.size();
        vector<vector<int>>adjR(v);
       vector<int>indegree(v,0);
        for(int i=0;i<graph.size();i++){
          for(auto& it:graph[i]){
              adjR[it].push_back(i);
              indegree[i]++;
          }
        }
queue<int>q;
        for(int i=0;i<v;i++){
          if(indegree[i]==0)q.push(i);
        }

        while(!q.empty()){
          int top=q.front();
          q.pop();
          ans.push_back(top);
          for(auto& it:adjR[top]){
            indegree[it]--;
            if(indegree[it]==0){
              q.push(it);
            }
          }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};