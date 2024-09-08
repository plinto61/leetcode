class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int start=0, zeros=0, result=0;
        for(int end=0; end < n; end++) {
            if(nums[end] == 0) {
                zeros++;
            }
            if(zeros > k) {
                while(nums[start] != 0 && start < end) {
                    start++;
                }
                start++;
                zeros--;
            }
            result = max(result, end-start+1);
        }
        return result;
    }
};