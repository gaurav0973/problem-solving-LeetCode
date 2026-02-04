class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        multiset<int> negativeBag;
        vector<int> ans;
        int n = nums.size();

        int l = 0, r = 0;

        while (r <= k - 2) {
            if (nums[r] < 0) {
                negativeBag.insert(nums[r]);
            }
            r++;
        }

        while (r < n) {

            if (nums[r] < 0) {
                negativeBag.insert(nums[r]);
            }

            while (r - l + 1 > k) {
                if (nums[l] < 0) {
                    negativeBag.erase(negativeBag.find(nums[l]));
                }
                l++;
            }

            
            if (negativeBag.size() >= x) {
                int cnt = 1;
                for(auto val : negativeBag){
                    if(cnt == x){
                        ans.push_back(val);
                        break;
                    }
                    cnt++;
        
                }
            } else {
                ans.push_back(0);
            }

            r++;
        }

        return ans;
    }
};
