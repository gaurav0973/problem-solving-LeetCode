class Solution {
public:
    typedef pair<int,int> P;
    vector<P> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        
        queue<P> q;
        int level = 0;
        
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';

        while(q.size()){
            int size = q.size();
            while(size--){
                auto pr = q.front(); q.pop();
                int x = pr.first;
                int y = pr.second;

                if ((x == 0 || x == n-1 || y == 0 || y == m-1) && !(x == entrance[0] && y == entrance[1]))
                    return level;
                
                for(auto dir : directions){
                    int x_ = x + dir.first;
                    int y_ = y + dir.second;

                    if (x_ < 0 || y_ < 0 || x_ >= n || y_ >= m || maze[x_][y_] == '+')
                        continue;

                    q.push({x_, y_});
                    maze[x_][y_] = '+';
                }
            }
            level++;
        }
        
        return -1;
    }
};