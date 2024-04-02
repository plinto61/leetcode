class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> track;
        int n = temperatures.size();
        vector<int> result(n, 0);
        int i = 0;
        while (i < n) {
            if (i == n - 1) {
                result[i] = 0;
                break;
            }
            track.push(i);
            int j = i + 1;
            while (j < n && !track.empty()) {
                int trackTop = track.top();
                if (temperatures[trackTop] < temperatures[j]) {
                    result[trackTop] = j - trackTop;
                    track.pop();
                } else {
                    track.push(j++);
                }
            }
            i = j;
        }
        return result;
    }
};