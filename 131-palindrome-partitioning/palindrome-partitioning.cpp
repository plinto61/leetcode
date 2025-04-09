class Solution {
    vector<vector<string>> result;
    vector<string> subset;

public:
    bool isPalindrom(string s) {
        int start = 0, end = s.size() - 1;
        while (start <= end) {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }
    void tryall(int i, string s) {
        if (i == s.size()) {
            bool isValidSubset = true;
            for (string s : subset) {
                isValidSubset = isValidSubset && isPalindrom(s);
            }
            if (isValidSubset)
                result.push_back(subset);
            return;
        }
        // add as new
        subset.push_back(string() + s[i]);
        tryall(i + 1, s);
        subset.pop_back();

        string last;
        last = subset.back();
        subset.pop_back();
        // add to previous
        subset.push_back(last + s[i]);
        tryall(i + 1, s);
        subset.pop_back();
        subset.push_back(last);
    }
    vector<vector<string>> partition(string s) {
        subset.push_back(string() + s[0]);
        tryall(1, s);
        return result;
    }
};