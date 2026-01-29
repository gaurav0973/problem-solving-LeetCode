class Solution {
public:
    typedef pair<int, string> p;
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        int n = words.size();
        unordered_map<string, int> f;
        for(int i=0; i<n; i++){
            f[words[i]]++;
        }
        auto lambda = [](p &a, p &b){
            if(a.first != b.first)
                return a.first > b.first;
            return a.second < b.second;
        };
        priority_queue<p, vector<p>, decltype(lambda)> minH;
        for(auto &it : f){
            int freq = it.second;
            string str = it.first;
            if(minH.size() < k){
                minH.push({freq, str});
                continue;
            }

            if(freq > minH.top().first
            || (freq == minH.top().first && str < minH.top().second)){
                minH.pop();
                minH.push({freq, str});
            }
        }

        while(minH.size() > 0){
            ans.push_back(minH.top().second);
            minH.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};