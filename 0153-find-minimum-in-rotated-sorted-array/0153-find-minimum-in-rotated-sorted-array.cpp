class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int start = 0, end = arr.size() - 1;
        int ansIdx = -1;
        while(start<=end){
            int guess = (start+end)/2;
            if(arr[guess] > arr[n-1]){
                start = guess + 1;
            }else{
                ansIdx = guess;
                end = guess-1;
            }
        }
        return arr[ansIdx];
    }
};