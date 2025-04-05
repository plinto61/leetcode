class Solution {
public:
    long long calculateHour(vector<int>& piles, int k) {

        if (k == 0)
            return LONG_MAX;
        long long sum = 0;
        for (auto pile : piles) {
            sum += (pile + k - 1) / k;
        }
        return sum;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = 1000000000;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long hours = calculateHour(piles, mid);
            if (hours <= h) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};