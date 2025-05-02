class Solution {

public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 1)
            return s;

        vector<vector<bool>> tab(n, vector<bool>(n, false));

        int max_start = 0, max_length = 1;
        for (int i = 0; i < n; i++) {
            tab[i][i] = true;
            if (i < n - 1) {
                if (s[i] == s[i + 1]) {
                    tab[i][i + 1] = true;
                    max_start = i;
                    max_length = 2;
                }
            }
        }
        for (int length = 3; length <= n; length++) {
            for (int start = 0; start <= n - length; start++) {
                int end = start+length-1;
                if (s[start] == s[end] &&
                    tab[start + 1][end - 1]) {
                    tab[start][end] = true;
                    if (length > max_length) {
                        max_length = length;
                        max_start = start;
                    }
                }
            }
        }
        return s.substr(max_start, max_length);
    }
};