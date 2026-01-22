class Solution {
public:
    int compress(vector<char>& chars) {
        string ans = "";
        int n = chars.size();
        int cnt=1;
        for(int i=1; i<n; i++){
            if(chars[i] == chars[i-1]){
                cnt++;
                continue;
            }
            ans+=chars[i-1];
            if(cnt>1){
                ans = ans + to_string(cnt);
            }
            cnt = 1;
        }

        // last ttraversal 
        ans+=chars[n-1];
        if(cnt>1){
            ans = ans + to_string(cnt);
        }

        for(int i=0; i<ans.size(); i++){
            chars[i] = ans[i];
        }
        return ans.size();
    }
};