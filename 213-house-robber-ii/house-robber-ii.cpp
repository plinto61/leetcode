class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);
        int i_n_1 = 0, e_n_1 = 0, i_n_2 = 0, e_n_2 = 0;

        for (int i = 0; i < n; i++) {
            if (i < n - 1) calc(nums[i], i_n_1, i_n_2);
            if (i > 0) calc(nums[i], e_n_1, e_n_2);
        }
        return max(i_n_1, e_n_1);
    }
    void calc(int num_i, int& n_1, int& n_2) {
        int temp = max(n_1, n_2 + num_i);
        n_2 = n_1;
        n_1 = temp;
    }
};