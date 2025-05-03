class Solution {
    unordered_map<string, bool> table;
public:
    
    bool wordBreak(string s, vector<string>& wordDict) {
        // cout << s << endl;
        if(s.size() == 0) return true;
        if(table.find(s) != table.end()) return table[s];
        bool ans = false;
        for(string word : wordDict) {
            if(s.size() < word.size()) continue;
            if(word == s.substr(0,word.size())) {
                table[s] = wordBreak(s.substr(word.size()), wordDict);
                ans = ans || table[s];
            }
        }
        return ans;
    }
};