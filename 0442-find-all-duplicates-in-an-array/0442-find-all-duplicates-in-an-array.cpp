class Solution {
public:
    vector<int> findDuplicates(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        for(int i=0; i<n; i++){
            int num = abs(arr[i]);
            int idx = num-1;
            
            // already visited
            if(arr[idx] < 0){
                ans.push_back(num);
                continue;
            }
            arr[idx] = -1*arr[idx];
        }
        return ans;
    }
};