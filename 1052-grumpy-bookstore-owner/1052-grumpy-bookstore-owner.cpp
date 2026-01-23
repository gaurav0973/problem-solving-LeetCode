class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int ans = 0;
        int n = customers.size();
        for(int i=0; i<n; i++){
            if(grumpy[i] == 0)
                ans+=customers[i];
        }


        int l=0, r=0, maxSum = 0;
        int sum = 0;
        while(r <= minutes-2){
            if(grumpy[r] == 1)
                sum+=customers[r];
            r++;
        }

        while(r<n){
            if(grumpy[r] == 1){
                sum+= customers[r];
            }

            maxSum = max(maxSum, sum);

            if(grumpy[l] == 1){
                sum-=customers[l];
            }
            l++;
            r++;
        }
        return ans + maxSum;
    }
};