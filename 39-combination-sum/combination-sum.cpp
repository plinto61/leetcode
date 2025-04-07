class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> subset;
        tryall(candidates, 0, subset, result, target);
        return result;
    }
    void tryall(vector<int>& nums, int i, vector<int>& subset,
                vector<vector<int>>& result, int target) {
        if (nums.size() == i) {
            if (target == 0) {
                result.push_back(subset);
            }
            return;
        }
        if (nums[i] <= target) {
            subset.push_back(nums[i]);
            tryall(nums, i, subset, result, target - nums[i]);
            subset.pop_back();
        }
        tryall(nums, i + 1, subset, result, target);
    }
};