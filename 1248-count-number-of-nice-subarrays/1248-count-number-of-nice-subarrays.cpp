class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return sumLessThan(nums,k) - sumLessThan(nums, k-1);
    }
    int sumLessThan(vector<int> &nums, int goal){
        if(goal < 0)
            return 0;

        int n = nums.size();
        int l = 0;
        int r = 0;
        int cnt = 0;
        int sum = 0;
        while(r < n){
            sum = sum +  (nums[r]%2);
            while(sum > goal){
                sum = sum -  (nums[l]%2);
                l++;
            }
            cnt = cnt +  (r-l+1);
            r++;
        }
        return cnt;
    }
};