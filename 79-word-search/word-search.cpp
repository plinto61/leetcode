class Solution {
    unordered_set<string> visited;
    bool result = false;

public:
    bool exist(vector<vector<char>>& board, string word) {
        unordered_map<char, int> count;
        for(char c : word) {
            count[c]++;
        }
        if(count[word[0]] > count[word.back()]) {
            reverse(word.begin(), word.end());
        }
        int m = board.size(), n = board[0].size();
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                tryall(x, y, 0, board, word);
                if (result)
                    return true;
            }
        }
        return result;
    }
    void tryall(int x, int y, int i, vector<vector<char>>& board, string word) {
        if (result || !isValidCoordinate(x, y, board, word[i]))
            return;
        visited.insert(to_string(x) + "," + to_string(y));
        if (++i == word.size()) {
            result = true;
            return;
        }
        tryall(x + 1, y, i, board, word);
        tryall(x - 1, y, i, board, word);
        tryall(x, y + 1, i, board, word);
        tryall(x, y - 1, i, board, word);
        visited.erase(to_string(x) + "," + to_string(y));
    }
    bool isValidCoordinate(int x, int y, vector<vector<char>>& board, char c) {
        if (x < 0 || y < 0 || x + 1 > board.size() || y + 1 > board[0].size() ||
            visited.count(to_string(x) + "," + to_string(y)) ||
            board[x][y] != c)
            return false;
        return true;
    }
};