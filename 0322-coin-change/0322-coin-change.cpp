class Solution {
public:
    int solve(vector<int> &nums, int idx, int amt, vector<vector<int>> &t){
        if(idx == 0){
            if(amt%nums[idx] == 0){
                return amt/nums[idx];
            }
            return 1e9;
        }

        if(t[idx][amt] != -1)
            return t[idx][amt];

        int take = 1e9;
        if(amt >= nums[idx])
            take = 1 + solve(nums, idx, amt-nums[idx], t);
        int notTake = solve(nums, idx-1, amt, t);
        return t[idx][amt]= min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> t(n+1, vector<int>(amount+1, -1));
        int ans = solve(coins, n-1, amount, t);
        return ans == 1e9 ? -1 : ans;
    }
};