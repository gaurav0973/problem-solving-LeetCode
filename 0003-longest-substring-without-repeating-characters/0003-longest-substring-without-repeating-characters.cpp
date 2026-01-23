class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0,  r = 0;
        int n = s.size();
        unordered_map<char, int> f;
        int maxLen = 0;
        while(r < n){
            f[s[r]]++;

            while(r-l+1 > f.size()){
                f[s[l]]--;
                if(f[s[l]] == 0)
                    f.erase(s[l]);
                l++;
            }

            maxLen = max(maxLen, r-l+1);
            r++;
        }

        return maxLen;
    }
};