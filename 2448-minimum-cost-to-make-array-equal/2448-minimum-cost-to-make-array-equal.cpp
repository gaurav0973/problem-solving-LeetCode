class Solution {
public:
    long long solve(vector<int> &nums, vector<int> &cost, int x){
        int n = nums.size();
        long long cnt = 0;
        for(int i=0; i<n; i++){
            cnt += (abs((long long)nums[i] - x)*cost[i]);
        }
        return cnt;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long start = nums[0];
        long long end = nums[0];
        for(long long x : nums){
            start = min(start, x);
            end = max(end, x);
        }

        long long ans = 0;
        while(start <= end){
            long long guess = start + (end - start) / 2;
            long long costGuess = solve(nums, cost, guess);
            long long costGuess1 = solve(nums, cost, guess+1);
            if(costGuess1 > costGuess){
                ans = costGuess;
                end = guess-1;
            }else{
                start = guess + 1;
            }
        }

        return ans;
    }
};