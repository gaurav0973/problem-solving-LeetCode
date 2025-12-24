class Solution {
public:
    int solve(unordered_map<char,int> &have, unordered_map<char,int> &need)
    {
        int ans = INT_MAX;
        for(auto &pair: need){
            int c = pair.first;
            int fNeed = pair.second;
            int fHave = have[c];
            int times = fHave/fNeed;
            ans = min(ans, times);
        }
        return ans;
    }
    int maxNumberOfBalloons(string text) {
        int n = text.size();
        unordered_map<char,int> have, need;
        for(int i=0; i<n; i++){
            have[text[i]]++;
        }
        string s = "balloon";
        for(int i=0; i<s.size(); i++){
            need[s[i]]++;
        }

        return solve(have, need);
    }
};