class Solution {
public:
    void dfs(int u, vector<vector<int>> &adj, vector<bool> &visited){

        visited[u] = true;
        for(auto &v : adj[u]){
            if(!visited[v]){
                dfs(v, adj, visited);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        dfs(0, rooms, visited);
        for(int i=0;i<n; i++){
            if(visited[i] == false)
                return false;
        }
        return true;
    }
};