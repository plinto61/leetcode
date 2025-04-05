class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        int left = 0, right = rows * cols - 1;
        while (left <= right) {
            int mid = (int)(left + right) / 2;
            int row = (int)mid / cols, col = mid % cols;
            cout << "left: " << left << "\tmid: " << mid << "\tright: " << right << endl;
            cout << "row: " << row << "\tcol: " << col << endl;

            if (target == matrix[row][col]) {
                return true;
            }

            if (target > matrix[row][col]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};