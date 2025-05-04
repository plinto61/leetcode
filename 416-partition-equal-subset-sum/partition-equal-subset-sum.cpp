class Solution {

public:
    bool itp(vector<int>& nums, int t, int i, vector<vector<int>>& hash) {
        if (t == 0)
            return true;

        if (i >= nums.size() || t < 0)
            return false;

        if (hash[t][i] == -1) {
            hash[t][i] = itp(nums, t, i + 1, hash) || itp(nums, t - nums[i], i + 1, hash);
        }

        return hash[t][i];
    }

    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (int n : nums) {
            total += n;
        }

        if (total % 2 != 0)
            return false;

        int target = total / 2;

        vector<vector<int>> hash(target + 1, vector<int>(nums.size(), -1));

        return itp(nums, target, 0, hash);
    }
};