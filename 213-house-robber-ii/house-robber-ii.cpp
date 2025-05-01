class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> first__robbed(n,0), second_robbed(n,0);
        first__robbed[0] = nums[0];
        if(n == 1)
            return nums[0];
        
        first__robbed[1] = nums[0];
        second_robbed[1] = nums[1];
        if(n == 2)
            return max(nums[0], nums[1]);

        for(int i=2;i<n-1;i++) {
            first__robbed[i] = max(nums[i] + first__robbed[i-2], first__robbed[i-1]);
            second_robbed[i] = max(nums[i] + second_robbed[i-2], second_robbed[i-1]);
        }
        first__robbed[n-1] = first__robbed[n-2];
        second_robbed[n-1] = max(nums[n-1] + second_robbed[n-3], second_robbed[n-2]);

        return max(first__robbed[n-1], second_robbed[n-1]);
    }
};