class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int bestEnding = nums[0];
        int ans = nums[0];
        for(int i=1; i<nums.size(); i++){
            int x = bestEnding + nums[i];
            int y = nums[i];
            bestEnding = max(x,y);
            ans = max(bestEnding, ans);
        }
        return ans;
    }
};