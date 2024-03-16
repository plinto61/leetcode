class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        if (n == 0) {
            return false;
        }
        if(n == 1) {
            return true;
        }
        int i = 0, j = n - 1;
        bool isPlaindrome = true;
        while (i < j) {
            char a = s[i], b = s[j];
            bool continueLoop = false;
            if (!isAlphaNumeric(a)) {
                i++;
                continueLoop = true;
            }
            if (!isAlphaNumeric(b)) {
                j--;
                continueLoop = true;
            }
            if (continueLoop) {
                continue;
            }
            if (convertToSmall(a) != convertToSmall(b)) {
                isPlaindrome = false;
                break;
            }
            i++;
            j--;
        }
        return isPlaindrome;
    }

    bool isAlphaNumeric(char c) {
        return isSmall(c) || isCapital(c) || isNumber(c);
    }

    char convertToSmall(char c) {
        if (isCapital(c)) {
            return (char)(c - 'A' + 'a');
        }
        return c;
    }

    bool isSmall(char c) { return c >= 'a' && c <= 'z'; }

    bool isCapital(char c) { return c >= 'A' && c <= 'Z'; }

    bool isNumber(char c) { return c >= '0' && c <= '9'; }
};