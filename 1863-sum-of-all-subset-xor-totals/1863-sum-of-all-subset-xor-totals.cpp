class Solution {
public:
    int solve(vector<int> &nums, int idx, int sum){
        if(idx == -1){
            return sum;
        }

        int take = solve(nums, idx-1, sum^nums[idx]);
        int notTake = solve(nums, idx-1, sum);

        return take + notTake;

    }
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        return solve(nums, n-1, 0);
    }
};