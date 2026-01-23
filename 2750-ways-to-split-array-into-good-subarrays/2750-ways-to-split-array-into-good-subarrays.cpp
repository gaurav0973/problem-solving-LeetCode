class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {

        const int MOD = 1e9 + 7;
        int n = nums.size();
        int l = 0, r = 0;
        long long cnt = 1;

        while (r < n) {

            // skip zeros
            while (r < n && nums[r] == 0) {
                r++;
            }

            // no 1 at all
            if (r == n) return 0;

            l = r;   // current 1
            r++;

            // skip zeros after this 1
            while (r < n && nums[r] == 0) {
                r++;
            }

            // if next 1 exists, multiply
            if (r < n) {
                cnt = (cnt * (r - l)) % MOD;
            }
        }

        return cnt;
    }
};
