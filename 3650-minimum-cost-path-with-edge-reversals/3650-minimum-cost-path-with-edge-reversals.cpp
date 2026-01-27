class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<pair<int,int>>>adj;

        for(auto& it:edges){
          int u=it[0];
          int v=it[1];
          int wt=it[2];
          adj[u].push_back({v,wt});
          adj[v].push_back({u,2*wt});
        }


        vector<int>dist(n,INT_MAX);

        priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>>pq;
        pq.push({0,0});
        dist[0]=0;


        while(!pq.empty()){
          auto top=pq.top();
          int w=top.first;
          int node=top.second;
          pq.pop();
          if(node==n-1)return dist[n-1];

          for(auto& p:adj[node]){
            int adjnode=p.first;
            int wt=p.second;
            if(w+wt<dist[adjnode]){
              dist[adjnode]=w+wt;
              pq.push({dist[adjnode],adjnode});
            }
          }
        }
        return -1;
    }
};