class Solution {
public:
    typedef pair<int, int> p;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> f;
        int n = nums.size();
        for(int i=0; i<n; i++){
            f[nums[i]]++;
        }

        auto lambda = [](p &a, p &b){
            if(a.first != b.first)
                return a.first > b.first;
            return a.second > b.second;
        };
        priority_queue<p, vector<p> , decltype(lambda)> minH;
        for(auto it : f){
            int freq = it.second;
            int element = it.first;
            if(minH.size() < k){
                minH.push({freq, element});
                continue;
            }
            if(freq > minH.top().first){
                minH.pop();
                minH.push({freq, element});
            }
        }
        vector<int> ans;
        while(minH.size() > 0){
            ans.push_back(minH.top().second);
            minH.pop();
        }
        return ans;
    }
};