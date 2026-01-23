class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l =0, r = 0;
        int k = 2;
        int n = fruits.size();
        unordered_map<int, int> f;
        int maxLen = 0;
        while(r < n){
            f[fruits[r]]++;

            while(f.size() > k){
                f[fruits[l]]--;
                if(f[fruits[l]]==0)
                    f.erase(fruits[l]);
                l++;
            }

            maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};