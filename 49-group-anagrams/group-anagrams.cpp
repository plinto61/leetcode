class Solution {

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(string s : strs) {
            string sorted_s = s;
            sort(sorted_s.begin(), sorted_s.end());
            cout << sorted_s << " " << s << endl;
            if(mp.find(sorted_s) != mp.end()) {
                mp[sorted_s].push_back(s);
            } else {
                mp[sorted_s] = {s};
            }
        }
        vector<vector<string>> result;
        for(const auto& pair : mp) {
            result.push_back(pair.second);
        }
        return result;
    }
};