class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> f;
        f[0] = 1;
        int cnt = 0;
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            int y = sum - k;
            if(f.find(y) != f.end()){
                cnt += f[y];
            }
            f[sum]++;
        }
        return cnt;
    }
};