class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordListSet(wordList.begin(), wordList.end());
        unordered_map<string, bool> visited;
        queue<string> q;
        q.push(beginWord);
        visited[beginWord] = true;

        int level = 0;
        while(q.size()){
            int n = q.size();
            for(int i=1; i<=n; i++){
                string curr = q.front(); q.pop();

                if(curr == endWord)
                    return level+1;

                for(char ch='a'; ch <='z'; ch++){
                    for(int i=0; i<beginWord.size(); i++){
                        string temp = curr;
                        temp[i] = ch;

                        if(visited.find(temp) != visited.end())
                            continue;
                        if(wordListSet.find(temp) != wordListSet.end()){
                            q.push(temp);
                            visited[temp] = true;
                        }
                    }
                }   
            }
            level++;

        }
        return 0;
    }
};