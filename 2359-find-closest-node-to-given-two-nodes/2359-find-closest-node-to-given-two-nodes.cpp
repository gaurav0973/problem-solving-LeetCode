class Solution {
public:

    vector<int> getDist(vector<int>& edges, int start){

        int n = edges.size();
        vector<int> dist(n, -1);

        int d = 0;

        while(start != -1 && dist[start] == -1){
            dist[start] = d++;
            start = edges[start];
        }

        return dist;
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {

        vector<int> dist1 = getDist(edges, node1);
        vector<int> dist2 = getDist(edges, node2);

        int ans = -1;
        int best = INT_MAX;

        for(int i = 0; i < edges.size(); i++){

            if(dist1[i] == -1 || dist2[i] == -1)
                continue;

            int d = max(dist1[i], dist2[i]);

            if(d < best){
                best = d;
                ans = i;
            }
        }

        return ans;
    }
};