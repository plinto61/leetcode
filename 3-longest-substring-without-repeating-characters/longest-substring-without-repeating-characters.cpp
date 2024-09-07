class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n == 0 || n == 1) {
            return n;
        }
        if(n == 2 && s[0] == s[1]) {
            return 1;
        }

        int i=0, j=1, result=1;
        map<char, int> mp;
        mp = {
            {s[i], i}
        };
        while(j < n) {
            if(mp.find(s[j]) != mp.end()) {
                int f = mp[s[j]];
                for(int k=i; k <= f; k++) {
                    mp.erase(s[k]);
                }
                i = f+1;
            } else {
                if(j-i+1 > result) {
                    result = j-i+1;
                }
            }
            mp[s[j]] = j;
            j++;
        }
        return result;
    }
};