class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        
        int n = arr.size();
        int l=0, r=0;
        int sum = 0;
        while(r <= k-2){
            sum += arr[r];
            r++;
        }
        int cnt = 0;
        while(r < n){
            sum+= arr[r];

            double avg = sum/k;
            if(avg >= threshold)
                cnt++;
            sum-=arr[l];
            l++;
            r++;
        }
        return cnt;
    }
};