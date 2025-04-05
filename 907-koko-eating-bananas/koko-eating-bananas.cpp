class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left_k = 1, right_k = *max_element(piles.begin(), piles.end());
        int k = right_k;
        while (left_k <= right_k) {
            int curr_k = (left_k + right_k) / 2;
            // cout << "left: " << left_k << "\tright: " << right_k << endl;
            // cout << "curr_k: " << curr_k << "\t" << endl;
            int h_needed = 0;
            for (auto n : piles) {
                double curr_h = (double)n/curr_k;
                // cout << n << ": " << curr_h << ", ";
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
            // cout << endl << "k: " << k << endl << endl;
        }
        return k;
    }
};