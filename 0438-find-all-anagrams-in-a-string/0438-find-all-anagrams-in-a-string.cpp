class Solution {
public:
    bool isSolution(vector<int> &have, vector<int> &need){
        for(int i=0; i<256; i++){
            int haveF = have[i];
            int needF = need[i];
            if(haveF != needF)
                return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> have(256, 0), need(256, 0);
        int n = s.size();
        for(auto ch : p){
            need[ch-'a']++;
        }

        int l=0, r=0;
        vector<int> ans;
        while(r < n){
            have[s[r] - 'a']++;

            while(r-l+1 > p.size()){
                have[s[l] - 'a']--;
                if(have[s[l] - 'a'] < 0)
                    have[s[l] - 'a'] = 0;
                l++;
            }

            if(r-l+1 == p.size() && isSolution(have, need))
                ans.push_back(l);
            r++;
        }
        return ans;
    }
};