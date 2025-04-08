class Solution {
    vector<vector<int>> result;
    vector<int> subset;

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        tryall(0, target, candidates);
        return result;
    }
    void tryall(int i, int target, vector<int>& nums) {
        if(target == 0) {
            result.push_back(subset);
            return;
        }
        if (i >= nums.size() || nums[i] > target) return;

        // pick
        subset.push_back(nums[i]);
        tryall(i+1, target - nums[i], nums);
        while(++i < nums.size() && nums[i] == subset.back()){}
        subset.pop_back();

        // don't pick
        tryall(i, target, nums);
    }
};