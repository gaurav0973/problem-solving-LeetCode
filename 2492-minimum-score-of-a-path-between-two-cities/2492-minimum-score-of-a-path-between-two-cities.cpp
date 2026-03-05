class Solution {
public:
    typedef pair<int, int> P;
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<P>> adj;
        for(auto temp: roads){
            int u = temp[0];
            int v = temp[1];
            int w = temp[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }


        vector<bool> visited(n, false);
        int ans = INT_MAX;
        dfs(1, ans, adj, visited);
        return ans;
    }
    void dfs(int u, int &ans, unordered_map<int, vector<P>> &adj, vector<bool> &visited){
        visited[u] = true;
        // ans = min(ans, )
        for(auto &it : adj[u]){
            int v = it.first;
            int w = it.second;
            ans = min(ans, w);
            if(!visited[v]){
                dfs(v, ans, adj, visited);
            }
        }
    }
};