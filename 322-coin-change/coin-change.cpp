class Solution {
    unordered_map<int, int> mem;

public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0)
            return 0;

        if (mem.find(amount) != mem.end())
            return mem[amount];

        int min = -1;
        for (int coin : coins) {
            if (amount >= coin) {
                int res = 1 + coinChange(coins, amount - coin);

                if (res == 0)
                    continue;

                if (min == -1 || res < min)
                    min = res;
            }
        }
        return mem[amount] = min;
    }
};