class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalGasAvailable = 0;
        int totalMovingCost = 0;
        for(int i=0; i<n; i++){
            totalGasAvailable+=gas[i];
            totalMovingCost+=cost[i];
        }
        if(totalMovingCost > totalGasAvailable)
            return -1;

        int total = 0;
        int ansIdx = 0;
        for(int i=0; i<n; i++){
            total += (gas[i] - cost[i]);
            if(total < 0){
                total = 0;
                ansIdx = i+1;
            }
        }
        return ansIdx;
    }
};