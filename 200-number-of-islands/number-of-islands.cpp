class Solution {
    vector<int> di = {1, -1, 0, 0};
    vector<int> dj = {0, 0, 1, -1};

public:
    void islandMarker(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j) {
        visited[i][j] = true;
        for (int p = 0; p < 4; p++) {
            int newI = i + di[p];
            int newJ = j + dj[p];

            if (newI >= 0 
                && newJ >= 0 
                && newI < grid.size() 
                && newJ < grid[0].size() 
                && grid[newI][newJ] == '1'
                && !visited[newI][newJ]
            ) {
                cout << "\tvalid";
                islandMarker(grid, visited, newI, newJ);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), count = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    count++;
                    islandMarker(grid, visited, i, j);
                }
            }
        }
        return count;
    }
};