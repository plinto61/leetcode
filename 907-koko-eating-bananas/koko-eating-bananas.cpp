class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left_k = 1, right_k = 1000000000;
        int k = right_k;
        while (left_k <= right_k) {
            int curr_k = (left_k + right_k) / 2;
            long long h_needed = 0;
            for (auto n : piles) {
                long long curr_h = (n + curr_k - 1)/curr_k;
                h_needed += ceil(curr_h);
                if (h_needed > h) {
                    break;
                }
            }
            if (h_needed > h) {
                left_k = curr_k + 1;
            } else {
                if (curr_k < k) {
                    k = curr_k;
                }
                right_k = curr_k - 1;
            }
        }
        return k;
    }
};