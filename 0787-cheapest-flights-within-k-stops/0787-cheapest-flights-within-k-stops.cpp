class Solution {
public:
    typedef pair<int,int> P;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<P>> adj;
        for(auto &temp: flights){
            int u = temp[0];
            int v = temp[1];
            int w = temp[2];
            adj[u].push_back({v,w});
        }

        vector<int> result(n, INT_MAX);

        queue<pair<int,P>> q;
        q.push({0,{src,0}});

        result[src] = 0;

        while(q.size()){

            auto temp = q.front();
            q.pop();

            int stop = temp.first;
            int u = temp.second.first;
            int cost = temp.second.second;

            for(auto &it : adj[u]){

                int v = it.first;
                int w = it.second;

                if(cost + w < result[v] && stop <= k){
                    result[v] = cost + w;
                    q.push({stop+1,{v,cost+w}});
                }
            }
        }

        return result[dst] == INT_MAX ? -1 : result[dst];
    }
};