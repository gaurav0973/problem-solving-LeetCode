class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        vector<int> leftOfI(n);
        vector<int> rightOfI(n);
        leftOfI[0] = arr[0];
        for(int i=1; i<n; i++){
            leftOfI[i] = max(leftOfI[i-1], arr[i-1]);
        }
        
        rightOfI[n-1] = arr[n-1];
        for(int i=n-2; i>=0; i--){
            rightOfI[i] = max(rightOfI[i+1], arr[i+1]);
        }
        
        
        int sum = 0;
        for(int i=0; i<n; i++){
            int h = min(leftOfI[i], rightOfI[i]);
            sum += max(0, h-arr[i]);
        }
        return sum;
    }
};