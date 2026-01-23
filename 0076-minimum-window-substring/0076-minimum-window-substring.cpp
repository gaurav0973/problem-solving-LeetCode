class Solution {
public:

    bool sahiHai(vector<int> &have, vector<int> &need) {
        for(int i = 0; i < 256; i++) {
            if(have[i] < need[i]) 
                return false;
        }
        return true;
    }
    string minWindow(string s, string t) {

        int n = s.size();
        vector<int> need(256, 0);
        vector<int> have(256, 0);
        
        for(char c : t) 
            need[c]++;

        int l = 0;
        int r = 0;
        int minLen = INT_MAX;
        int startIdx = 0;

        while(r < n) {

            have[s[r]]++;
            while(sahiHai(have, need)) {
                int len = r - l + 1;
                if(len < minLen) {
                    minLen = len;
                    startIdx = l;
                }
                have[s[l]]--; 
                l++;
            }
            r++;
        }

        return minLen == INT_MAX ? "" : s.substr(startIdx, minLen);
    }
};
