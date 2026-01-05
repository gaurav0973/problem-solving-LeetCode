class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0, end = arr.size() - 1;
        int ans = -1;
        while(start<=end){
            int guess = (start+end)/2;
            if(arr[guess] < arr[guess+1]){
                start = guess + 1;
            }else{
                ans = guess;
                end = guess-1;
            }
        }
        return ans;
    }
};