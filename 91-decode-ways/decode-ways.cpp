class Solution {
    unordered_map<string, int> codeHash;

public:
    bool isImpossible(string s) {
        if (s[0] == '0')
            return true;
        char prev = s[0];
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '0') {
                if (prev == '0' || (prev != '1' && prev != '2'))
                    return true;
            }
            prev = s[i];
        }
        return false;
    }
    int getWays(string s) {
        if (codeHash[s])
            return codeHash[s];
        if (s[0] == '0')
            return 0;
        if (s.size() == 0 || s.size() == 1)
            return 1;

        if (s[0] == '1' || (s[0] == '2' && s[1] >= '0' && s[1] <= '6')) {
            codeHash[s] = getWays(s.substr(1)) + getWays(s.substr(2));
        } else {
            codeHash[s] = getWays(s.substr(1));
        }
        return codeHash[s];
    }
    int numDecodings(string s) {
        if (isImpossible(s))
            return 0;
        int ans = getWays(s);
        for (auto& i : codeHash) {
            cout << i.first << ": " << i.second << endl;
        }
        return ans;
    }
};