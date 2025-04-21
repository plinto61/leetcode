class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size();
        long lowest = 0, highest = 0;
        vector<long> hidden(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            hidden[i] = hidden[i - 1] + differences[i - 1];
            lowest = hidden[i] < lowest ? hidden[i] : lowest;
            highest = hidden[i] > highest ? hidden[i] : highest;
        }
        int allowedRange = upper - lower, currRange = highest - lowest;
        if (currRange > allowedRange)
            return 0;
        return allowedRange - currRange + 1;
    }
};