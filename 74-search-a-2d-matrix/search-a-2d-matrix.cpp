class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix[0].size(), n = matrix.size();
        int low = 0, high = m*n-1;
        while(low <= high) {
            int mid = (high+low)/2;
            int row = mid/m, col = mid%m;
            if(matrix[row][col] == target) {
                return true;
            }

            if(matrix[row][col] > target) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return false;
    }
};