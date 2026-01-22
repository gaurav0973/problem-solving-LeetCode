class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto num: nums) sum+=num;

        int LSum = 0;
        for(int i=0; i<n; i++){
            if(i>0)
                LSum += nums[i-1];
            int RSum = sum-nums[i] - LSum;
            if(LSum == RSum)
                return i;
        }
        return -1;
    }
};