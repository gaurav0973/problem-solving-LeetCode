class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0;
        int l = 0, r = 0, n = nums.size();
        unordered_map<int, int> f;
        long long sum = 0;

        while(r <= k-2){
            sum += nums[r];
            f[nums[r]]++;
            r++;
        }

        while(r < n){
            f[nums[r]]++;
            sum += nums[r];

            if(f.size() == k){
                ans = max(ans, sum);
            }

            f[nums[l]]--;
            sum -= nums[l];
            if(f[nums[l]] == 0)
                f.erase(nums[l]);
            l++;
            r++;
        }
        return ans;
    }
};