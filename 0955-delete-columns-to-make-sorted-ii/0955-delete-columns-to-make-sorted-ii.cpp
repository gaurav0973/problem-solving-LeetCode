class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int deletions = 0;
        
        // cuts[i] = true if strs[i] < strs[i+1] already
        vector<bool> cuts(n - 1, false);
        
        for (int col = 0; col < m; col++) {
            bool deleteThisCol = false;
            
            // Check if we need to delete this column
            for (int i = 0; i < n - 1; i++) {
                if (!cuts[i] && strs[i][col] > strs[i+1][col]) {
                    deleteThisCol = true;
                    break;
                }
            }
            
            if (deleteThisCol) {
                deletions++;
            } else {
                // Mark new cuts
                for (int i = 0; i < n - 1; i++) {
                    if (!cuts[i] && strs[i][col] < strs[i+1][col]) {
                        cuts[i] = true;
                    }
                }
            }
        }
        
        return deletions;
    }
};