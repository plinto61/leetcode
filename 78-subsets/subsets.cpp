class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        tryall(nums, 0, subset, result);
        return result;
        
    }
    void tryall(vector<int>& nums, int i, vector<int>& subset, vector<vector<int>>& result) {
        
        while(i < nums.size()) {
            subset.push_back(nums[i]);
            tryall(nums, ++i, subset, result);
            subset.pop_back();
        }
        result.push_back(subset);
    }
};
