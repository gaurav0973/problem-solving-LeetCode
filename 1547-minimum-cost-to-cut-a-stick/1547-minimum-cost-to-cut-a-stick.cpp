class Solution {
public:

    int solve(vector<int>& cuts, int l, int r, vector<vector<int>> &t){
        if(r-l < 2){
            return 0;
        }
        if(t[l][r] != -1)
            return t[l][r];


        int ans = INT_MAX;
        for(int i=l+1; i<=r-1; i++){
            int cost = (cuts[r]-cuts[l])
                        + solve(cuts, l, i, t)
                        + solve(cuts, i, r, t);
            ans = min(ans, cost);
        }
        return t[l][r] = ans;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(begin(cuts), end(cuts));
        cuts.insert(begin(cuts), 0);
        cuts.push_back(n);
        vector<vector<int>> t(103, vector<int>(103, -1));
        return solve(cuts, 0, cuts.size()-1, t);
    }
};