class Solution {
public:
    vector<int> ans;
    void countAndMerge(vector<pair<int,int>>& arr, int l, int mid, int r) {
        int i = l, j = mid + 1;
        vector<pair<int,int>> temp;

        while (i <= mid && j <= r) {
            if (arr[i].first <= arr[j].first) {
                // j - (mid+1) elements from right are already smaller
                ans[arr[i].second] += (j - mid - 1);
                temp.push_back(arr[i]);
                i++;
            } else {
                temp.push_back(arr[j]);
                j++;
            }
        }

        while (i <= mid) {
            ans[arr[i].second] += (j - (mid + 1));
            temp.push_back(arr[i]);
            i++;
        }
        while (j <= r) {
            temp.push_back(arr[j]);
            j++;
        }

        for (int k = l; k <= r; k++) {
            arr[k] = temp[k - l];
        }
    }

    void solve(vector<pair<int,int>>& arr, int l, int r) {
        if (l >= r) return;

        int mid = (l + r) / 2;
        solve(arr, l, mid);
        solve(arr, mid + 1, r);
        countAndMerge(arr, l, mid, r);
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        ans.assign(n, 0);

        vector<pair<int,int>> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        solve(arr, 0, n - 1);
        return ans;
    }
};
