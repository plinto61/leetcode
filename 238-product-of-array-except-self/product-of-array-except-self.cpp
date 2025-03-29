class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int p = 0;
        bool has_one_zero = false, has_two_zeroes = false;
        for(int i=0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                if(has_one_zero) {
                    has_two_zeroes = true;
                    break;
                }
                has_one_zero = true;
                continue;
            }
            if(p == 0) {
                p = nums[i];
            } else {
                p *= nums[i];
            }
        }
        cout << "p: " << p << endl;
        vector<int> result(nums.size());
        if(has_two_zeroes) {
            for(int i=0; i<nums.size(); i++) {
                result[i] = 0;
            }
        } else {
            for(int i=0; i<nums.size(); i++) {
                if(has_one_zero) {
                    if(nums[i] == 0) {
                        result[i] = p;
                    } else {
                        result[i] = 0;
                    }
                } else {
                    result[i] = static_cast<int>(p/nums[i]);
                }
            }
        }
        return result;
    }
};