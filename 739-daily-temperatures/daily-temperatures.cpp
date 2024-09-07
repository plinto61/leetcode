class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> st;
        for(unsigned int i=0; i < n; i++) {
            if(st.empty() || temperatures[st.top()] >= temperatures[i]) {
                st.push(i);
                continue;
            }
            while(!st.empty() && temperatures[st.top()] < temperatures[i]) {
                int ci = st.top();
                result[ci] = i-ci;
                st.pop();
            }
            st.push(i);
        }
        return result;
    }
};