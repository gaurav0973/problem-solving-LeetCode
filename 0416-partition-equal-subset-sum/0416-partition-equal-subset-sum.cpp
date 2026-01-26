class Solution {
public:
    bool solve(vector<int> &nums, int idx, int target, vector<vector<int>> &t){
        if(target == 0)
            return true;
        if(idx == 0){
            if(target == nums[0])
                return true;
            return false;
        }
        if(t[idx][target] != -1)
            return t[idx][target];

        bool notTake = solve(nums, idx-1, target, t);
        bool take = false;
        if(nums[idx] <= target)
            take = solve(nums, idx-1, target-nums[idx], t);

        return t[idx][target] = take || notTake;

    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for(auto x : nums ) totalSum+=x;

        if(totalSum %2 == 1)
            return false;

        vector<vector<int>> t(n, vector<int>(totalSum/2 + 1, -1));
        return solve(nums, n-1, totalSum/2, t);
    }
};