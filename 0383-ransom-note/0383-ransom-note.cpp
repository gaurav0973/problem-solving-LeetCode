class Solution {
public:
    bool solve(unordered_map<char,int> &have, unordered_map<char,int> &need)
    {
        for(auto &pair: need){
            int c = pair.first;
            int fNeed = pair.second;
            int fHave = have[c];
            if(fHave < fNeed)
                return false;
        }
        return true;
    }
    bool canConstruct(string ransomNote, string magazine) {
        int n = magazine.size();
        int m = ransomNote.size();
        unordered_map<char,int> have, need;
        for(int i=0; i<n; i++){
            have[magazine[i]]++;
        }
        for(int i=0; i<m; i++){
            need[ransomNote[i]]++;
        }
        return solve(have, need);
    }
};