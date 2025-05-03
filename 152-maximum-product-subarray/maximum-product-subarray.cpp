class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = *max_element(nums.begin(), nums.end());
        int curr_max = 1, curr_min = 1;
        for(int n : nums) {
            int max_temp = curr_max*n, min_temp = curr_min*n;
            curr_max = max({max_temp, min_temp, n});
            curr_min = min({max_temp, min_temp, n});

            res = max(res, curr_max);
        }
        return res;
    }
};