class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        int noDelete = nums[0];
        int oneDelete = 0;
        int ans = nums[0];
        for(int i=1; i<n; i++){
            int prevOneDelete = oneDelete; 
            int prevNoDelete = noDelete;
            noDelete = max(noDelete+nums[i], nums[i]);
            oneDelete = max(prevOneDelete+nums[i], prevNoDelete);
            ans = max({ans, oneDelete, noDelete});
        }
        return ans;
    }
};