class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int start = 1;
        int end = 1e9;
        // for (int i = 0; i < n; i++) {
        //     start = min(bloomDay[i], start);
        //     end = max(bloomDay[i], end);
        // }

        int ans = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (isPossibleAns(mid, bloomDay, m, k)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }

    bool isPossibleAns(int mid,vector<int> &nums, int m, int k)
    {
        int cnt = 0;
        int total = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] <= mid)
                cnt++;
            else
                cnt = 0;
            
            if(cnt == k){
                cnt = 0;
                total++;
            }
            if(total == m)
                return true;
        }
        return false;
    }
};