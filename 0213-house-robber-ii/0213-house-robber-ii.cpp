class Solution {
public:
    int solve(vector<int>& nums, int idx, int start, vector<int> &t) {
        if(idx < start){
            return 0;
        }

        if(t[idx] != -1)
            return t[idx];

        int take = nums[idx] + solve(nums, idx-2, start, t);
        int notTake = 0 + solve(nums, idx-1, start, t);
        return t[idx] = max(take, notTake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        vector<int> t1(n, -1); 
        vector<int> t2(n, -1);
        return max(solve(nums, n-1, 1, t1), solve(nums, n-2, 0, t2));
    }
};