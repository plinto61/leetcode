class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> subset;
        tryall(candidates, 0, subset, result, target);
        return result;

    }
    void tryall(vector<int>&nums, int i, vector<int>& subset, vector<vector<int>>& result, int target) {
        int sum = get_sum(subset);
        // cout << "i: " << i << "\tsum: " << sum << "\t";
        // print_vec(subset);
        if(sum == target) {
            result.push_back(subset);
            return;
        }
        if(sum > target) {
            return;
        }
        if(i < nums.size()) {
            subset.push_back(nums[i]);
            tryall(nums, i, subset, result, target);
            subset.pop_back();
            tryall(nums, ++i, subset, result, target);
        }
    }
    int get_sum(vector<int>& subset) {
        int sum=0;
        for(int num : subset) {
            sum += num;
        }
        return sum;
    }
    void print_vec(vector<int>& vec) {
        cout << "[";
        for(int i=0; i<vec.size(); i++) {
            if(i != vec.size()-1) {
                cout << vec[i] << ", ";
            } else {
                cout << vec[i];
            }
        }
        cout << "]" << endl;
    }
};
/*
[2,3,5], 8

[2] [2,2]   [2,2,2] [2,2,2,2]============
                    [2,2,2,3]n
                    [2,2,2,5]n
            [2,2,3] [2,2,3,3]n
                    [2,2,3,5]n
            [2,2,5]n
    [2,3]   [2,3,3]===============
            [2,3,5]n
    [2,5]   [2,5,5]n
[3] [3,3]   [3,3,3]n
            [3,3,5]n
    [3,5]==============
[5] [5,5]n
    
*/