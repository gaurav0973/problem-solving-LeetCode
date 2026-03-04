class Solution {
public:
    void dfs(int u, int depth, unordered_map<int, vector<int>> &adj, vector<int> &distance, vector<bool> &visited){

        visited[u] = true;
        distance[u] = depth;

        for(auto &v : adj[u]){
            if(!visited[v]){
                dfs(v, depth+1, adj, distance, visited);
            }
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {

        int n = edges.size();
        unordered_map<int, vector<int>> adj;
        for(int u=0; u<n; u++){
            int v = edges[u];
            if(v != -1){
                adj[u].push_back(v);
            }
        }

        vector<bool> visited1(n,false);
        vector<bool> visited2(n,false);

        vector<int> distance1(n,INT_MAX);
        vector<int> distance2(n,INT_MAX);

        dfs(node1,0,adj,distance1,visited1);
        dfs(node2,0,adj,distance2,visited2);

        int ansIdx = -1;
        int minD = INT_MAX;
        for(int i=0;i<n;i++){
            
            

            int maxD = max(distance1[i],distance2[i]);

            if(maxD < minD){
                minD = maxD;
                ansIdx = i;
            }
        }

        return ansIdx;
    }
};