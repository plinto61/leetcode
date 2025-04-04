class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int duplicate;
        for(int i=0; i<nums.size(); i++) {
            int abs_val = abs(nums[i]);
            int idx = abs_val - 1;
            if(nums[idx] < 0) {
                duplicate = abs_val;
                break;
            }
            nums[idx] = 0 - nums[idx];
        }
        return duplicate;
    }
};