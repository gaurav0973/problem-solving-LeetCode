class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        deque<int> dq;
        vector<int> ans;
        int n = nums.size();
        int l = 0, r = 0;

        while(r <= k-2){
            while(dq.size() > 0 && nums[r] > nums[dq.back()])
                dq.pop_back();
            dq.push_back(r);
            r++;
        }

        while (r < n) {

            // 1. Insert nums[r] into monotonic queue correctly
            while (dq.size()>0 && nums[r] > nums[dq.back()])
                dq.pop_back();
            dq.push_back(r);
            
            while(dq.size()>0 && dq.front() < l){
                dq.pop_front();
            }

            ans.push_back(nums[dq.front()]);
            l++;
            r++;
        }

        return ans;
    }
};
