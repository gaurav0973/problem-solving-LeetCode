class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        
        int breakPoint = -1;
        // findind the first positive
        for(int i=0; i<n; i++){
            if(nums[i] >= 0){
                breakPoint = i;
                break;
            }
        }
        if(breakPoint == -1){
            for(int i=0;i<n; i++){
                nums[i] = nums[i]*nums[i];
            }
            sort(nums.begin(), nums.end());
            return nums;
        }
        int i = breakPoint - 1;
        int j = breakPoint;
        while(i>=0 && j<n)
        {
            int lftSq = nums[i]*nums[i];
            int rhtSq = nums[j]*nums[j];
            if(lftSq <= rhtSq){
                ans.push_back(lftSq);
                i--;
            }
            else{
                ans.push_back(rhtSq);
                j++;
            }
        }
        while(i>=0)
        {
            int lftSq = nums[i]*nums[i];
            ans.push_back(lftSq);
            i--;
        }
        while(j<n)
        {
            int rhtSq = nums[j]*nums[j];
            ans.push_back(rhtSq);
            j++;
        }
        return ans;

        
    }
};