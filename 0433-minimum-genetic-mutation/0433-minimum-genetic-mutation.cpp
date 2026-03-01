class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> bankSet(bank.begin(), bank.end());
        unordered_map<string, bool> visited;
        string str = "ACGT";
        queue<string> q;
        q.push(startGene);
        visited[startGene] = true;

        int level = 0;
        while(q.size()){
            int n = q.size();
            for(int i=1; i<=n; i++){
                string curr = q.front(); q.pop();

                if(curr == endGene)
                    return level;

                for(int i=0; i<4; i++){
                    for(int j=0; j<8; j++){
                        string temp = curr;
                        temp[j] = str[i];

                        if(visited.find(temp) != visited.end())
                            continue;
                        if(bankSet.find(temp) != bankSet.end()){
                            q.push(temp);
                            visited[temp] = true;
                        }
                    }
                }   
            }
            level++;

        }
        return -1;
        
    }
};