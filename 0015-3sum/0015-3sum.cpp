class Solution {
public:
    vector<vector<int>> twoSumDup(vector<int> &nums, int start, int end, int target)
    {
        vector<vector<int>> temp;
        while(start < end)
        {
            int sum = nums[start] + nums[end];
            if(sum == target){
                temp.push_back({nums[start], nums[end]});
                start++;
                end--;

                while(start < end && nums[start] == nums[start-1])
                    start++;
                while(start < end && nums[end] == nums[end+1])
                    end--;
            }
            else if(sum > target)
                end--;
            else
                start++;
        }
        return temp;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        if(n < 3)
            return ans;
        
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n - 2; i++){
            if(i > 0 && nums[i] == nums[i-1])
                continue;
                
            int target = -nums[i];
            vector<vector<int>> pairs = twoSumDup(nums, i + 1, n - 1, target);
            
            for(auto &pair : pairs){
                ans.push_back({nums[i], pair[0], pair[1]});
            }
        }
        return ans;
    }
};