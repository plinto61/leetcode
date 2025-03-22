class Solution {

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(auto s : strs) {
            string sorted_s = s;
            sort(sorted_s.begin(), sorted_s.end());
            mp[sorted_s].push_back(s);
        }
        vector<vector<string>> result;
        for(auto x : mp) {
            result.push_back(x.second);
        }
        return result;
    }
};