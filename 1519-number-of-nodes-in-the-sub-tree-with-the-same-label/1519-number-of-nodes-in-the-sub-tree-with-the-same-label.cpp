class Solution {
public:
    vector<int> dfs(int u, int parent, vector<vector<int>> &adj, vector<int> &ans, string &labels) {
        
        vector<int> myCount(26, 0);
        myCount[labels[u] - 'a'] = 1;

        for(int v : adj[u]) {
            if(v == parent) 
                continue;

            vector<int> childCount = dfs(v, u, adj, ans, labels);

            for(int i = 0; i < 26; i++)
                myCount[i] += childCount[i];
        }
        ans[u] = myCount[labels[u] - 'a'];
        return myCount;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        for(auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> ans(n);
        dfs(0, -1, adj, ans, labels);
        return ans;
    }
};