class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size();
        if (s.size() <= 2) {
            return true;
        }
        int i=0, j=n-1;
        int i_ = -1, j_ = -1;
        bool onceDeleted = false;
        while(i<j) {
            // cout << s << endl;
            // for(int x =0; x < n; x++) {
            //     if(x == i || x == j) {
            //         cout << "^";
            //     } else {
            //         cout << " ";
            //     }
            // }
            // cout << endl;
            if(s[i] == s[j]) {
                i++;
                j--;
                continue;
            }
            if(onceDeleted) {
                if(i_ >= 0) {
                    i=i_;
                    j=j_;
                    i_ = -1;
                    j_ = -1;
                    continue;
                } else {
                    return false;
                }
            }
            if(j-i == 1) {
                return true;
            }
            if(s[i] == s[j-1] && s[i+1] == s[j]) {
                i_ = i+1;
                j_ = j--;
            } else if(s[i] == s[j-1]) {
                j--;
            } else if(s[i+1] == s[j]) {
                i++;
            } else {
                return false;
            }
            onceDeleted = true;
        }
        return true;
    }
};