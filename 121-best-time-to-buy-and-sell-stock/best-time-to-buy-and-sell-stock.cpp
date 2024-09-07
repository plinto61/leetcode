class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int result = 0;
        if(n == 1) {
            return 0;
        }
        int i=0, j=1;

        while(i < n-1) {
            if(prices[j] <= prices[i]) {
                i++;
                j = i+1;
                continue;
            }
            int diff = prices[j] - prices[i];
            if(diff > result) {
                result = diff;
            }
            if(j == n-1) {
                i++;
                j = i+1;
            } else {
                j++;
            }
        }
        return result;
    }
};