class Solution {

public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> mem(amount + 1, amount + 1);
        mem[0] = 0;

        for (int curr_amount = 1; curr_amount <= amount; curr_amount++) {
            for (int coin : coins) {
                if (curr_amount >= coin) {
                    mem[curr_amount] =
                        min(mem[curr_amount], 1 + mem[curr_amount - coin]);
                }
            }
            // cout << curr_amount << "\t" << mem[curr_amount] << endl;
        }
        return mem[amount] == amount + 1 ? -1 : mem[amount];
    }
};