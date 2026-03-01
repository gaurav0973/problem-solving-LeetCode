class Solution {
public:
    vector<int> Leader;
    vector<int> Rank;
    int find(int x){
        if(Leader[x] == x)
            return x;
        return Leader[x] = find(Leader[x]);
    }

    void Union(int x, int y){
        int Lx = find(x);
        int Ly = find(y);
        if(Lx == Ly)
            return;
        if(Rank[Lx] == Rank[Ly]){
            Leader[Lx] = Ly;
            Rank[Ly]++;
        }else if(Rank[Lx] > Rank[Ly]){
            Leader[Ly] = Lx;
        }else{
            Leader[Lx] = Ly;
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        Leader.resize(n);
        Rank.resize(n);
        for(int i=0; i<n; i++){
            Leader[i] = i;
            Rank[i] = 0;
        }


        for(int i=0; i<n; i++){
            int r = stones[i][0];
            int c = stones[i][1];
            for(int j=i+1; j<n; j++){
                if(stones[j][0] == r || stones[j][1] == c)
                    Union(i,j);
            }
        }

        int nGrp = 0;
        for(int i=0; i<n; i++){
            if(Leader[i] == i)
                nGrp++;
        }
        return n - nGrp;
    }
};