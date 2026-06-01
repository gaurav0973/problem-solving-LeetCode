class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<bool> row(n,false);
        vector<bool> col(n,false);

        //1. find which row and col me zero hai
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 0){
                    row[i] = true;
                    col[j] = true;
                }
            }
        }

        //2. apply the condition
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(row[i]==true || col[j]==true){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};