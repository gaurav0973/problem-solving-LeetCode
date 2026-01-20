class Solution {
public:
    void solve(vector<int> &nums, int idx, vector<vector<int>> &subsets, vector<int> &temp){
        if(idx == -1){
            subsets.push_back(temp);
            return;
        }

        temp.push_back(nums[idx]);
        solve(nums, idx-1, subsets, temp);

        temp.pop_back();
        solve(nums, idx-1, subsets, temp);

    }
    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> temp;
        int n = nums.size();
        solve(nums, n-1, subsets, temp);

        int ans = 0;
        for(int i=0; i<subsets.size(); i++){
            vector<int> t = subsets[i];
            int x = 0;
            for(int j=0; j<t.size(); j++){
                x = x^t[j];
            }
            ans +=x;
        }

        return ans;
    }
};