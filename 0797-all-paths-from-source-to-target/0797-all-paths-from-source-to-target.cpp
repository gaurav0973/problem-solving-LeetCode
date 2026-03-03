class Solution {
public:
    void dfs(int u, int target, vector<int> &temp, vector<vector<int>> &ans, vector<vector<int>> &adj){
        temp.push_back(u);
        if(u==target){
            ans.push_back(temp);
            temp.pop_back();
            return;
        }

        for(auto &v : adj[u]){
            dfs(v, target, temp, ans, adj);
        }

        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> temp;
        vector<vector<int>> ans;
        dfs(0, n-1, temp, ans, adj);
        return ans;
    }
};