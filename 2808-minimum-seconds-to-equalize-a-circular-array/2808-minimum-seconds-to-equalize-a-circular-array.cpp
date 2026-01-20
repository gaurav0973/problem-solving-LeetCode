class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> f;
        for(int i=0; i<n; i++){
            f[nums[i]].push_back(i);
        }

        int ans = INT_MAX;
        for(auto &line : f){
            int value = line.first;
            vector<int> positions = line.second;

            int posLen = positions.size();
            for(int i=0; i<posLen; i++){
                positions.push_back(positions[i] + n);
            }

            int maxGap = INT_MIN;
            for(int i=1; i<positions.size(); i++){
                maxGap = max(maxGap, positions[i] - positions[i-1]);
            }
            
            ans = min(ans, maxGap/2);

        }
        return ans;
    }
};