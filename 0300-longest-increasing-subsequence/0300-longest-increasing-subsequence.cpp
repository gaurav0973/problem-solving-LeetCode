class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> LIS(n, 1);
        int cnt = 1;

        for(int idx=1; idx<n; idx++){
            for(int prev=0; prev<idx; prev++){
                if(nums[idx] > nums[prev])
                    LIS[idx] = max(LIS[idx], 1 + LIS[prev]);
            }
            cnt = max(cnt, LIS[idx]);
        }
        return cnt;
    }
};