class Solution {
public:
    int findPivit(vector<int> &arr) {
        // Code Here
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
        return ansIdx;
    }
    int BS(vector<int> &arr, int x, int start, int end) {
        while(start<=end){
            int guess = (start+end)/2;
            if(arr[guess] == x)
                return guess;
            else if(arr[guess] < x){
                start = guess + 1;
            }else{
                end = guess -1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int idx = findPivit(nums);
        int x = BS(nums, target, 0, idx-1);
        if(x != -1)
            return x;
        return BS(nums, target, idx, nums.size()-1);
    }
};