class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size();
        long lowest = 0, highest = 0, curr = 0;
        for (int i = 0; i < n; i++) {
            curr = curr + differences[i];
            lowest = curr < lowest ? curr : lowest;
            highest = curr > highest ? curr : highest;
        }
        
        int allowedRange = upper - lower, currRange = highest - lowest;
        if (currRange > allowedRange)
            return 0;
        return allowedRange - currRange + 1;
    }
};