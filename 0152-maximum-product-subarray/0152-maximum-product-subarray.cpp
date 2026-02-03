class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = -1e9;
        int prefix = 1;
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                ans = max(0, ans);
                prefix = 1;
                continue;
            }
            prefix*=nums[i];
            ans = max(ans, prefix);
        }

        int suffix = 1;
        for(int i=n-1; i>=0; i--){
            if(nums[i] == 0){
                ans = max(0, ans);
                suffix = 1;
                continue;
            }
            suffix*=nums[i];
            ans = max(ans, suffix);
        }
        return ans;
    }
};