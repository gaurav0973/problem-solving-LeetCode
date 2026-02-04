class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_map<string, int> f;
        int l = 0, r = k-1;
        int n = s.size();

        while(r < n){
            string str = s.substr(l, r-l+1);
            f[str]++;

            l++;
            r++;
        }

        return f.size() == (1 << k);
    }
};