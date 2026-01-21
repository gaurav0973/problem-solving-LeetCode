class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        while(i < n){

            int correctIdx = nums[i];
            if(correctIdx < n && nums[i] != nums[correctIdx]){
                swap(nums[i], nums[correctIdx]);
            }else{
                i++;
            }
            
        }

        int ans = n;
        for(int i=0; i<n; i++){
            if(nums[i] != i){
                ans = i;
                break;
            }
        }
        return ans;
    }
};