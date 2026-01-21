class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int maxLen = 0;
        unordered_map<char, int> f;
        while(r<s.size())
        {   //1. include 
            f[s[r]]++;
            
            // 2. jabtak galat hai shrink karo 
            int len = r-l+1;
            while(f.size() < len)
            {
                f[s[l]]--;
                if(f[s[l]] == 0)
                    f.erase(s[l]);
                l++;
                len = r-l+1;
            }

            // 3. some calculations
            maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};