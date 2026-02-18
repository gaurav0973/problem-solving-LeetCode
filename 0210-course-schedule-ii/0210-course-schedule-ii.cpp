class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;

        // Graph creation
        vector<vector<int>> adj(n);
        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            //u -> v
            adj[u].push_back(v);
        }

        // In-degree
        vector<int> indegree(n, 0);
        for (int u = 0; u < n; u++) {
            for (auto &v : adj[u]) {
                indegree[v]++;
            }
        }

        // Initialize queue
        queue<int> q;
        for (int u = 0; u < n; u++) {
            if (indegree[u] == 0) {
                q.push(u);
            }
        }

        // BFS
        vector<int> ans;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            ans.push_back(u);

            for (auto &v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) { 
                    q.push(v);
                }
            }
        }

        if (ans.size() != n) {
            return {};
        }
        return ans;
    }
};