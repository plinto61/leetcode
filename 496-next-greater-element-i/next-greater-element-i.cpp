class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1_len = nums1.size(), n2_len = nums2.size();
        vector<int> result;
        for(unsigned int i=0; i < n1_len; i++) {
            int search_elem = true;
            int found_next_greatest = false;
            for(unsigned int j=0; j < n2_len; j++) {
                if(search_elem) {
                    if(nums2[j] == nums1[i]) {
                        search_elem = false;
                    }
                } else {
                    if(nums2[j] > nums1[i]) {
                        found_next_greatest = true;
                        result.push_back(nums2[j]);
                        break;
                    }
                }
            }
            if(!found_next_greatest) {
                result.push_back(-1);
            }
        }
        return result;
    }
};