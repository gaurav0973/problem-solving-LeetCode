class Solution {
public:
    int mergeAndCount(vector<int>& nums, int l, int mid, int r) {
        int cnt = 0;

        // ⭐ count reverse pairs
        int j = mid + 1;
        for (int i = l; i <= mid; i++) {
            while (j <= r && (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }
            cnt += (j - (mid + 1));
        }

        // normal merge
        vector<int> temp;
        int i = l;
        j = mid + 1;

        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i++]);
            } else {
                temp.push_back(nums[j++]);
            }
        }

        while (i <= mid) temp.push_back(nums[i++]);
        while (j <= r) temp.push_back(nums[j++]);

        for (int k = l; k <= r; k++) {
            nums[k] = temp[k - l];
        }

        return cnt;
    }

    int solve(vector<int>& nums, int l, int r) {
        if (l >= r) return 0;

        int mid = (l + r) / 2;
        int count = 0;

        count += solve(nums, l, mid);
        count += solve(nums, mid + 1, r);
        count += mergeAndCount(nums, l, mid, r);

        return count;
    }

    int reversePairs(vector<int>& nums) {
        return solve(nums, 0, nums.size() - 1);
    }
};
