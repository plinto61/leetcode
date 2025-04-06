class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int r = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            r ^= nums[i] ^ i;
        }
        return r ^ nums.size();
    }
};