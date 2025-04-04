class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (right >= left) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            cout << "left: " << left << "\tmid: " << mid << "\tright: " << right
                 << endl;
            if (nums[mid] < target) {
                left = mid == left ? mid + 1 : mid;
            } else {
                right = mid == right ? mid - 1 : mid;
            }
        }
        return -1;
    }
};