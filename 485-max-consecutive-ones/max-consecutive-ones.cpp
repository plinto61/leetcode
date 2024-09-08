class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_count = 0, curr_count = 0;
        for(int i=0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                if(curr_count > max_count) {
                    max_count = curr_count;
                }
                curr_count = 0;
            } else {
                curr_count++;
            }
        }
        if(curr_count > max_count) {
            max_count = curr_count;
        }
        return max_count;
    }
};