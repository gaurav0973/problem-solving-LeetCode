class Solution {
public:
    int countWhileMerge(vector<long long>& prefix, int l, int mid, int r,
                        int lower, int upper) {
        int cnt = 0;
        int j1 = mid + 1, j2 = mid + 1;

        // ⭐ counting step
        for (int i = l; i <= mid; i++) {
            while (j1 <= r && prefix[j1] < prefix[i] + lower) j1++;
            while (j2 <= r && prefix[j2] <= prefix[i] + upper) j2++;
            cnt += (j2 - j1);
        }

        // normal merge
        vector<long long> temp;
        int i = l, j = mid + 1;

        while (i <= mid && j <= r) {
            if (prefix[i] <= prefix[j]) temp.push_back(prefix[i++]);
            else temp.push_back(prefix[j++]);
        }

        while (i <= mid) temp.push_back(prefix[i++]);
        while (j <= r) temp.push_back(prefix[j++]);

        for (int k = l; k <= r; k++) {
            prefix[k] = temp[k - l];
        }

        return cnt;
    }

    int solve(vector<long long>& prefix, int l, int r,
              int lower, int upper) {
        if (l >= r) return 0;

        int mid = (l + r) / 2;
        int cnt = 0;

        cnt += solve(prefix, l, mid, lower, upper);
        cnt += solve(prefix, mid + 1, r, lower, upper);
        cnt += countWhileMerge(prefix, l, mid, r, lower, upper);

        return cnt;
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        return solve(prefix, 0, n, lower, upper);
    }
};
