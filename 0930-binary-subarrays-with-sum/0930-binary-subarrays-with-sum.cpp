class Solution {
public:
    int solve(vector<int> nums, int k){
        int l = 0, r= 0;
        if(k == -1)
            return 0;

        int sum = 0;
        int cnt = 0;
        while(r < nums.size()){
            sum+=nums[r];
            while(l <= r && sum > k){
                sum-=nums[l];
                l++;
            }

            cnt += (r-l+1);
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums, goal) - solve(nums, goal-1);
    }
};