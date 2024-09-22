class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1, mid = nums.size()/2;
        while(right-left > 1) {
            if(nums[mid] > target) {
                right = mid;
            } else if(nums[mid] < target) {
                left = mid;
            } else {
                return mid;
            }
            mid = (left+right)/2;
        }
        if(nums[left] == target) {
            return left;
        }
        if(nums[right] == target) {
            return right;
        }
        return -1;
    }
};