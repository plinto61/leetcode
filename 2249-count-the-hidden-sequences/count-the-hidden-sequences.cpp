class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size();
        long l = 0, h = 0, curr = 0;
        for (int i = 0; i < n; i++) {
            curr += differences[i];
            if(curr < l) l = curr;
            if(curr > h) h = curr;
        }
        if (h - l > upper - lower)
            return 0;
        return upper - lower - h + l + 1;
    }
};