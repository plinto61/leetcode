class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> t(m, vector<int>(n, 0));
        t[0][0] = text1[0] == text2[0];
        for (int i = 1; i < m; i++) {
            t[i][0] = text1[i] == text2[0] || t[i - 1][0];
        }
        for (int i = 1; i < n; i++) {
            t[0][i] = text2[i] == text1[0] || t[0][i - 1];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                t[i][j] = (text1[i] == text2[j])
                              ? 1 + t[i - 1][j - 1]
                              : max(t[i - 1][j], t[i][j - 1]);
            }
        }
        // for (int i = -1; i < m; i++) {
        //     if (i >= 0) {
        //         cout << text1[i];
        //     }
        //     for (int j = 0; j < n; j++) {
        //         if (i == -1) {
        //             cout << "\t" << text2[j];
        //         } else {
        //             cout << "\t" << t[i][j];
        //         }
        //     }
        //     cout << endl;
        // }
        return t[m - 1][n - 1];
    }
};