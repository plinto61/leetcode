class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++) {
            int s = target-nums[i];
            if(mp.find(s) != mp.end()) {
                return {mp[s], i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};