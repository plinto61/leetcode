class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1_len = nums1.size(), n2_len = nums2.size();
        map<int, int> mp;
        for(unsigned int i=0; i < n2_len; i++) {
            mp[nums2[i]] = i;
        }
        vector<int> result;
        for(unsigned int i=0; i < n1_len; i++) {
            int num = -1;
            for(unsigned int j=mp[nums1[i]]+1; j < n2_len; j++) {
                if(nums2[j] > nums1[i]) {
                    num = nums2[j];
                    break;
                }
            }
            result.push_back(num);
        }
        return result;
    }
};