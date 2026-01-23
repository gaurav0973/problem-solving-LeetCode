class Solution {
public:
    int findMaxCount(unordered_map<char,int>& f) {
        int mx = 0;
        for (auto &it : f) {
            mx = max(mx, it.second);
        }
        return mx;
    }

    int characterReplacement(string s, int k) {
        int l = 0, r = 0;
        int n = s.size();
        int maxLen = 0;
        unordered_map<char, int> f;

        while (r < n) {
            f[s[r]]++;

            int windowSize = r - l + 1;
            int maxCount = findMaxCount(f);
            int replacements = windowSize - maxCount;

            while (replacements > k) {
                f[s[l]]--;
                if (f[s[l]] == 0)
                    f.erase(s[l]);
                l++;

                windowSize = r - l + 1;
                maxCount = findMaxCount(f);
                replacements = windowSize - maxCount;
            }

            maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }
};
