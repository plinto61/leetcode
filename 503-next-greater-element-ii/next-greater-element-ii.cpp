class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        for(unsigned int i=0; i < n; i++) {
            int num = -1;
            for(unsigned int j=1; j < n; j++) {
                unsigned int a = (i+j)%n;
                if(nums[a] > nums[i]) {
                    num = nums[a];
                    break;
                }
            }
            result.push_back(num);
        }
        return result;
    }
};