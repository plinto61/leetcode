class Solution {
public:
    bool isValid(string s) {
        stack<char> track;
        for (auto& c : s) {
            if (isOpen(c)) {
                track.push(c);
                continue;
            }
            if (track.empty()) {
                return false;
            }
            char top = track.top();
            if (isValidPair(top, c)) {
                track.pop();
                continue;
            }
            return false;
        }
        return track.empty();
    }
    bool isOpen(char c) { return c == '(' || c == '[' || c == '{'; }
    bool isValidPair(char o, char c) {
        return (o == '(' && c == ')') || (o == '[' && c == ']') ||
               (o == '{' && c == '}');
    }
};