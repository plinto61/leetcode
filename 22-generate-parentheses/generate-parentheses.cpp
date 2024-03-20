class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        actualFunc(0, n, result, "");
        return result;
    }

private:
    void actualFunc(int open, int remain, vector<string>& result, string s) {
        if (remain == 0 && open == 0) {
            result.push_back(s);
        }
        if (remain > 0) {
            actualFunc(open + 1, remain - 1, result, s + '(');
        }
        if (open > 0) {
            actualFunc(open - 1, remain, result, s + ')');
        }
    }
};