class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size();
        unordered_map<char, int> f;
        for(int i=0; i<n; i++){
            f[s[i]]++;
        }
        int ansCnt = 0;
        bool isOdd = false;
        for(auto &pair: f){
            char c = pair.first;
            int chCnt = pair.second;
            if(chCnt%2 == 0){
                ansCnt+=chCnt;
            }
            else{
                isOdd = true;
                ansCnt+=(chCnt-1);
            }  
        }
        if(isOdd)
            ansCnt+=1;
        return ansCnt;
    }
};