class Solution {
    vector<vector<int>> result;
    vector<int> subset;

private:
    void tryall(int i, vector<int>& nums) {
        if (i == nums.size()) {
            result.push_back(subset);
            return;
        }

        // don't pick
        tryall(i + 1, nums);

        // pick
        subset.push_back(nums[i]);
        tryall(i + 1, nums);
        subset.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        tryall(0, nums);
        return result;
    }
};
