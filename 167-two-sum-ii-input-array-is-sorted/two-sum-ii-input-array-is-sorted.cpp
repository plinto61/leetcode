class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int i = 0, j = n - 1;
        vector<int> sol(2);
        while (true) {
            if (numbers[i] + numbers[j] == target) {
                sol[0] = i + 1;
                sol[1] = j + 1;
                break;
            } else if (numbers[i] + numbers[j] > target) {
                j--;
            } else {
                i++;
            }
        }
        return sol;
    }
};