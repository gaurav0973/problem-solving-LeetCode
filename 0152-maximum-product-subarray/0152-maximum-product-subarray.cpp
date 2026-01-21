class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        int prevBestMin = nums[0];
        int prevBestMax = nums[0];

        for(int i=1; i<n; i++){
            int x = nums[i];
            int y = prevBestMin*nums[i];
            int z = prevBestMax*nums[i];
            prevBestMin = min(x, min(y,z));
            prevBestMax = max(x, max(y,z));
            ans = max(ans, max(prevBestMin, prevBestMax));
        }

        return ans;
    }
};