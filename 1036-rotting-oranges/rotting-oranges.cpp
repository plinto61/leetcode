class Solution {
    vector<int> di = {1, -1, 0, 0};
    vector<int> dj = {0, 0, 1, -1};

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), time = 0;
        bool scopeForRotting = true;
        while (scopeForRotting) {
            // for (int i = 0; i < m; i++) {
            //     for (int j = 0; j < n; j++) {
            //         cout << grid[i][j] << "\t";
            //     }
            //     cout << endl;
            // }
            // cout << endl;
            scopeForRotting = false;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 2) {
                        // rott surroundings
                        for (int k = 0; k < 4; k++) {
                            int newi = i + di[k];
                            int newj = j + dj[k];
                            if (newi >= 0 && newi < m && newj >= 0 &&
                                newj < n && grid[newi][newj] == 1) {
                                scopeForRotting = true;
                                grid[newi][newj] = -1;
                            }
                        }
                    }
                }
            }
            if (!scopeForRotting)
                break;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == -1) {
                        scopeForRotting = true;
                        grid[i][j] = 2;
                    }
                }
            }
            time++;
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return time;
    }
};