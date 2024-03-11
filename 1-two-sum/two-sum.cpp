class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> track;
        int n = nums.size();

        track[nums[0]] = 0;
        vector<int> result(2);
        for(int i=1; i<n; i++) {
            if(track.find(target - nums[i]) == track.end()) {
                track[nums[i]] = i;
            } else {
                result[0] = track[target-nums[i]];
                result[1] = i;
                break;
            }
        }

        return result;
    }
};