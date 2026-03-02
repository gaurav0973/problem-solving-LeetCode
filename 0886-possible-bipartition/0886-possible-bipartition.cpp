class Solution {
public:
    bool dfs(int u, vector<int> &color, int currColor, 
             unordered_map<int, vector<int>> &adj){
        
        color[u] = currColor;

        for(int v : adj[u]){
            if(color[v] == currColor)
                return false;

            if(color[v] == -1){
                if(dfs(v, color, 1 - currColor, adj) == false)
                    return false;
            }
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        unordered_map<int, vector<int>> adj;

        for(auto &temp : dislikes){
            int u = temp[0];
            int v = temp[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> color(n+1, -1);

        for(int i = 1; i <= n; i++){
            if(color[i] == -1){
                if(dfs(i, color, 0, adj) == false)
                    return false;
            }
        }

        return true;
    }
};