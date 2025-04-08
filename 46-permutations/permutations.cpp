class Solution {
    vector<vector<int>> result;
    vector<int> subset;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        tryall(0, nums);
        return result;
    }
    void tryall(int i, vector<int>& nums) {
        if(i == nums.size()) {
            result.push_back(subset);
            return;
        }
        for(int num : nums) {
            if(!exists(num, subset)) {
                subset.push_back(num);
                tryall(i+1, nums);
                subset.pop_back();
            }
        }
    }
    bool exists(int val, vector<int>& vec) {
        for(int num : vec) {
            if(num == val) return true;
        }
        return false;
    }
};
/*
[1,2,3,4]
1
1   2
1   2   3
1   2   3   4 ->
1   2   4
1   2   4   3 ->
1   3
1   3   2
1   3   2   4 ->
*/