class Solution {
    vector<vector<int>> table;

public:
    int mp(vector<int>& prices, int i, int bi) {
        if (i >= prices.size())
            return 0;
        if (table[bi][i] < 0) {
            if (bi > 0) { // can sell
                table[bi][i] =
                    max((prices[i] - prices[bi - 1]) + mp(prices, i + 2, 0),
                        mp(prices, i + 1, bi));
            } else { // can buy
                table[bi][i] =
                    max(mp(prices, i + 1, i + 1), mp(prices, i + 1, 0));
            }
        }
        return table[bi][i];
    }
    int maxProfit(vector<int>& prices) {
        table.assign(prices.size() + 1, vector<int>(prices.size() + 1, -1));
        return mp(prices, 0, 0);
    }
};