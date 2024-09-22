class Solution {
private:
    void printVals(string s, int start, int n, int end, int charMap[],
                   int remaining) {
        for (int i = 0; i < 26; i++) {
            if (charMap[i] >= 0) {
                cout << charMap[i] << " ";
            }
        }
        cout << "= " << remaining << endl;
        for (int i = 0; i < 26; i++) {
            if (charMap[i] >= 0) {
                cout << (char)('a' + i) << " ";
            }
        }
        cout << endl;
        for (int i = 0; i < s.size(); i++) {
            cout << s[i];
        }
        cout << endl;
        for (int i = 0; i < s.size(); i++) {
            if (i < start || i >= start + n) {
                cout << " ";
            } else {
                if (i == end) {
                    cout << "^";
                } else {
                    cout << "-";
                }
            }
        }
        cout << endl;
    }

public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();

        int charMap[26];
        fill(charMap, charMap + 26, -1);
        for (int i = 0; i < n; i++) {
            int idx = s1[i] - 'a';
            if (charMap[idx] < 0) {
                charMap[idx] = 1;
            } else {
                charMap[idx]++;
            }
        }

        int left = 0, right = 0, remaining = n;

        while (left + n <= s2.size()) {
            // printVals(s2, left, n, right, charMap, remaining);
            // cout << "left: " << left << "\tright: " << right << endl;
            if(right-left == n) {
                if (charMap[s2[left] - 'a'] >= 0) {
                    charMap[s2[left] - 'a']++;
                    remaining++;
                }
                left++;
            } else if (charMap[s2[right] - 'a'] > 0) {
                charMap[s2[right++] - 'a']--;
                if (--remaining == 0) {
                    return true;
                }
            } else if (charMap[s2[right] - 'a'] == 0) {
                if (charMap[s2[left] - 'a'] >= 0) {
                    charMap[s2[left++] - 'a']++;
                    remaining++;
                } else {
                    left++;
                }
            } else {
                if (charMap[s2[left] - 'a'] >= 0) {
                    charMap[s2[left] - 'a']++;
                    remaining++;
                }
                right++;
                left++;
            }
        }

        return false;
    }
};