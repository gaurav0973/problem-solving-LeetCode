class Solution {
public:
    void dfs(int u, unordered_map<int, vector<int>> &adj, vector<bool> &visited){
        visited[u] = true;

        for(auto &v : adj[u]){
            if(!visited[v]){
                dfs(v,adj,visited);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> adj;
        for(auto temp : edges){
            int u = temp[0];
            int v = temp[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n,false);
        dfs(source,adj,visited);
        return visited[destination];
    }
};