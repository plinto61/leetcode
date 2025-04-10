class Solution {
public:
    int islandExplorer(int m, int n, int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1)
            return 0;
        grid[i][j] = -1;
        return 1 + islandExplorer(m, n, i + 1, j, grid) +
               islandExplorer(m, n, i - 1, j, grid) +
               islandExplorer(m, n, i, j + 1, grid) +
               islandExplorer(m, n, i, j - 1, grid);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), maxArea = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int currArea = islandExplorer(m, n, i, j, grid);
                    cout << "currArea: " << currArea << endl;
                    maxArea = max(maxArea, currArea);
                }
            }
        }
        return maxArea;
    }
};