class Solution {

public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> mem(amount + 1, -1);
        mem[0] = 0;

        for (int curr_amount = 1; curr_amount <= amount; curr_amount++) {
            for (int coin : coins) {
                if (curr_amount >= coin) {
                    int res = 1 + mem[curr_amount - coin];
                    if (res == 0)
                        continue;
                    if (mem[curr_amount] == -1 || res < mem[curr_amount])
                        mem[curr_amount] = res;
                }
            }
            // cout << curr_amount << "\t" << mem[curr_amount] << endl;
        }
        return mem[amount];
    }
};