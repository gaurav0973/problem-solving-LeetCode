class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 3) return 0;
        
        sort(nums.begin(), nums.end());
        int ans = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                //calculation 
                int diff = abs(sum-target);
                int ansDiff = abs(ans-target);
                if (diff < ansDiff) {
                    ans = sum;
                }
                if(sum == target) {
                    return sum;
                }
                else if(sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        
        return ans;
    }
};