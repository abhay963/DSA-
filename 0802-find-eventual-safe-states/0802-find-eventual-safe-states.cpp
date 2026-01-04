class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& state) {

        if (state[node] == 1) return false; // found cycle
        if (state[node] == 2) return true;  // already safe

        state[node] = 1; // visiting

        for (int neigh : graph[node]) {
            if (!dfs(neigh, graph, state)) {
                return false;   // neighbor leads to cycle
            }
        }

        state[node] = 2; // safe
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
          int n = graph.size();
        vector<int> state(n, 0);   // 0 = unvisited
        vector<int> result;

        for (int i = 0; i < n; i++) {
            if (dfs(i, graph, state)) {
                result.push_back(i);
            }
        }

        return result;
    }
};