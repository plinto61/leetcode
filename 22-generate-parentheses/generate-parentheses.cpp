class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string init = "";
        actualFunc(0, n, result, init);
        return result;
    }
    void actualFunc(int open, int remain, vector<string>& result, string& s) {
        if (remain == 0 && open == 0) {
            result.push_back(s);
        }  
        if (remain > 0) {
            string s1 = s + '(';
            actualFunc(open+1, remain-1, result, s1);
        }  
        if (open > 0) {
            string s1 = s + ')';
            actualFunc(open-1, remain, result, s1);
        }
    }
};