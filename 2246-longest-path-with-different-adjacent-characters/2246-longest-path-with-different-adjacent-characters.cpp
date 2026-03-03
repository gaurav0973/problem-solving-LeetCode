class Solution {
public:
    int ans = 0;

    int dfs(int u, vector<vector<int>> &adj, string &s) {
        int longest = 0;
        int secondLongest = 0;
        for(int v : adj[u]) {

            int childLength = dfs(v, adj, s);

            if(s[v] == s[u])
                continue;
            if(childLength > longest) {
                secondLongest = longest;
                longest = childLength;
            } else if(childLength > secondLongest) {
                secondLongest = childLength;
            }
        }

        ans = max(ans, 1 + longest + secondLongest);

        return 1 + longest;
    }

    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);

        for(int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }
        dfs(0, adj, s);
        return ans;
    }
};