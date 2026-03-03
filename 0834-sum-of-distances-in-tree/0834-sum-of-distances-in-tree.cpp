class Solution {
public:
    int N;
    long root_result = 0;
    vector<int> count; // count of number of subtree below including the node

    // First DFS
    int dfsBase(vector<vector<int>> &adj, int curr, int parent, int depth) {

        root_result += depth;
        int total = 1;

        for(int child : adj[curr]) {
            if(child == parent) 
                continue;
            total += dfsBase(adj, child, curr, depth + 1);
        }

        count[curr] = total;
        return total;
    }

    // Second DFS
    void dfs(vector<vector<int>> &adj, int curr, int prev, vector<int> &ans) {

        for(int child : adj[curr]) {
            if(child == prev) continue;

            ans[child] = ans[curr]
                         - count[child]
                         + (N - count[child]);

            dfs(adj, child, curr, ans);
        }
    }

    vector<int> sumOfDistancesInTree(int n,
                                     vector<vector<int>>& edges) {

        N = n;
        vector<vector<int>> adj(n);
        count.resize(n);

        for(auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfsBase(adj, 0, -1, 0);

        vector<int> ans(n);
        ans[0] = root_result;

        dfs(adj, 0, -1, ans);

        return ans;
    }
};