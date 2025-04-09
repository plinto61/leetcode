class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        unordered_map<char, int> count;
        for (char c : word) {
            count[c]++;
        }
        if (count[word[0]] > count[word.back()]) {
            reverse(word.begin(), word.end());
        }
        int m = board.size(), n = board[0].size();
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                if (tryall(x, y, 0, board, word))
                    return true;
            }
        }
        return false;
    }
    bool tryall(int x, int y, int i, vector<vector<char>>& board, string word) {
        if (!isValidCoordinate(x, y, board, word[i]))
            return false;
        char temp = board[x][y];
        board[x][y] = '\0';
        if (++i == word.size())
            return true;
        bool res = tryall(x + 1, y, i, board, word) ||
                   tryall(x - 1, y, i, board, word) ||
                   tryall(x, y + 1, i, board, word) ||
                   tryall(x, y - 1, i, board, word);
        board[x][y] = temp;
        return res;
    }
    bool isValidCoordinate(int x, int y, vector<vector<char>>& board, char c) {
        return x >= 0 && y >= 0 && x < board.size() && y < board[0].size() &&
               board[x][y] == c;
    }
};