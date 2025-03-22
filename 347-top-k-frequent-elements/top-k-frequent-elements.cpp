class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int num : nums) {
            if(mp.find(num) != mp.end()) {
                mp[num]++;
            } else {
                mp[num] = 1;
            }
        }
        vector<pair<int, int>> f;
        for(pair<int, int> p : mp) {
            f.push_back(p);
        }
        sort(f.begin(), f.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.second > b.second;
        });
        vector<int> result;
        for(int i=0; i<k; i++) {
            result.push_back(f[i].first);
        }
        
        return result;
    }
};