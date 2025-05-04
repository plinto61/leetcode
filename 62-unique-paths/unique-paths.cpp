class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> pp(m, vector<int>(n, 0));
        for(int i=0; i<m; i++) {
            pp[i][0] = 1;
        }
        for(int i=0; i<n; i++) {
            pp[0][i] = 1;
        }
        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                pp[i][j] = pp[i-1][j] + pp[i][j-1];
            }
        }
        return pp[m-1][n-1];
    }
};