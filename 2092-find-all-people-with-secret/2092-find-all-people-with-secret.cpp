class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        map<int,vector<pair<int,int>>>timeMeetings;
        for(auto& it:meetings){
          int p1=it[0];
          int p2=it[1];
          int time=it[2];
          timeMeetings[time].push_back({p1,p2});
        }


        vector<bool>knows(n,false);
        knows[0]=true;
        knows[firstPerson]=true;

        for(auto& it:timeMeetings){
           auto& vec = it.second;



          unordered_map<int,vector<int>>adj;
          unordered_set<int>st;
          queue<int>q;
          for (auto& edge : vec) {
                int p1 = edge.first;
                int p2 = edge.second;
                adj[p1].push_back(p2);
                adj[p2].push_back(p1);
            }
          
                for (auto& edge : vec) {
                if (knows[edge.first] && st.insert(edge.first).second)
                    q.push(edge.first);
                if (knows[edge.second] && st.insert(edge.second).second)
                    q.push(edge.second);
            }

while (!q.empty()) {
                int person = q.front();
                q.pop();

                for (int next : adj[person]) {
                    if (!st.count(next)) {
                        st.insert(next);
                        q.push(next);
                    }
                }
            }

            for (int p : st) {
                knows[p] = true;
            }
        }


        vector<int>ans;
        for(int i=0;i<n;i++){
          if(knows[i]==true)ans.push_back(i);
        }

        return ans;
    }
};