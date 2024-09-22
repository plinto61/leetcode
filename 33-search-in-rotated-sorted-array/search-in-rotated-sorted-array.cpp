class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            cout << "low: " << nums[low] << "\tmid: " << nums[mid]
                 << "\thigh: " << nums[high] << endl;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[low] == target) {
                return low;
            } else if (nums[high] == target) {
                return high;
            }

            if (nums[mid] > nums[high]) {
                if (target > nums[mid] || target < nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            } else if (nums[mid] < nums[low]) {
                if (target < nums[mid] || target > nums[low]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if (nums[mid] > target) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        return -1;
    }
};