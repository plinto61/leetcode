class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result;
        for(int i=0; i<=n; i++) {
            int j = i;
            int count = 0;
            while(j) {
                count += (j & 1);
                j = j >> 1;
            }
            result.push_back(count);
        }
        return result;
    }
};