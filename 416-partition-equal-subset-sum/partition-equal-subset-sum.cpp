class Solution {
    vector<vector<int>> hash;

public:
    bool itp(vector<int>& nums, int t, int i) {
        if (t == 0)
            return true;

        if (i == nums.size())
            return false;

        if (hash[t][i] == -1) {
            hash[t][i] = nums[i] > t ? itp(nums, t, i + 1)
                                     : itp(nums, t, i + 1) ||
                                           itp(nums, t - nums[i], i + 1);
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

        hash.assign(target+1, vector<int>(nums.size(), -1));

        return itp(nums, target, 0);
    }
};