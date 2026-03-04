class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        
        int n = s1.size();

        //creating a graph
        unordered_map<char,vector<char>> adj;
        for(int i=0; i<n; i++){
            char u = s1[i];
            char v = s2[i];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }


        n = baseStr.size();
        string ans;
        for(int i=0; i<n; i++){
            char ch = baseStr[i];
            vector<int> visited(26,0);
            char min_char = dfs(adj,ch,visited);
            ans.push_back(min_char);
        }


        return ans;
    }

    char dfs(unordered_map<char,vector<char>> &adj, char curr_char, vector<int>& visited)
    {
        visited[curr_char - 'a'] = 1;
        char min_char = curr_char;
        for(auto &v : adj[curr_char])
        {
            if(!visited[v - 'a']){
                min_char = min(min_char, dfs(adj,v,visited));
            }
        }
        return min_char;
    }

};