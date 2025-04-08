class Solution {

private:
    void tryall(int i, vector<int>& nums, vector<int>& subset, vector<vector<int>>& result) {
        if (i == nums.size()) {
            result.push_back(subset);
            return;
        }

        // don't pick
        tryall(i + 1, nums, subset, result);

        // pick
        subset.push_back(nums[i]);
        tryall(i + 1, nums, subset, result);
        subset.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        tryall(0, nums, subset, result);
        return result;
    }
};
