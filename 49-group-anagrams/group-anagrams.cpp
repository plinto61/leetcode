class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;

        unordered_map<string, vector<string>> track;

        for(auto str:strs) {
            string s = sort_str(str);
            track[s].push_back(str);
        }

        for(auto& [key, value]: track) {
            result.push_back(value);
        }

        return result;
    }

    string sort_str(string& str) {
        //
        int chars[26] = {0};

        for(auto c:str) {
            chars[c-'a']++;
        }
        
        string s;

        for(int i=0; i<26; i++) {
            for(int j=0; j<chars[i]; j++) {
                s += i+'a';
            }
        }
        return s;
    }
};