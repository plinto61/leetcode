class Solution {
    vector<pair<int, int>> directions = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    int m, n;

public:
    void bfs(int i, int j, vector<vector<int>>& heights, vector<vector<bool>>& ocean) {
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (auto dir : directions) {
                int newx = x + dir.first;
                int newy = y + dir.second;

                if (newx < 0 || newx >= m || newy < 0 || newy >= n) {
                    continue;
                }
                if (heights[newx][newy] < heights[x][y]) {
                    continue;
                }
                if(ocean[x][y] && !ocean[newx][newy]) {
                    ocean[newx][newy] = true;
                    q.push(make_pair(newx, newy));
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            pacific[i][0] = true;
            atlantic[i][n - 1] = true;
        }
        for (int j = 0; j < n; j++) {
            pacific[0][j] = true;
            atlantic[m - 1][j] = true;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                bfs(i, j, heights, pacific);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                bfs(i, j, heights, atlantic);
            }
        }

        vector<vector<int>> ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};