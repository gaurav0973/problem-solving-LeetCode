class Solution {
public:
    int dfs(int u, int parent, unordered_map<int, vector<int>> &adj, vector<bool> &hasApple){
        int time = 0;
        for(auto &v : adj[u]){
            if(v == parent)
                continue;
            
            int t = dfs(v, u, adj, hasApple);
            if(t > 0 || hasApple[v] )
                time += (t+2); 
        }
        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int, vector<int>> adj;
        for(auto &vec : edges) {
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return dfs(0, -1, adj, hasApple);
    }
};