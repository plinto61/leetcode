class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> calc_stack;
        for (auto& token : tokens) {
            if (isOperator(token)) {
                int num1 = calc_stack.top();
                calc_stack.pop();
                int num2 = calc_stack.top();
                calc_stack.pop();
                int result = getResult(num2, num1, token[0]);
                calc_stack.push(result);
            } else {
                int num = convertStringToInt(token);
                calc_stack.push(num);
            }
        }
        return calc_stack.top();
    }
    bool isOperator(string& token) {
        return token.size() == 1 && (token[0] == '+' || token[0] == '-' ||
                                     token[0] == '*' || token[0] == '/');
    }
    int convertStringToInt(string& token) {
        int multiplier = 1;
        int number = 0;
        for (int i = 0; i < token.size(); i++) {
            if (i == 0 && token[i] == '-') {
                multiplier = -1;
            } else {
                number = 10 * number + (token[i] - '0');
            }
        }
        return number * multiplier;
    }
    int getResult(int num1, int num2, char op) {
        if (op == '+') {
            return num1 + num2;
        } else if (op == '-') {
            return num1 - num2;
        } else if (op == '*') {
            return num1 * num2;
        } else {
            return num1 / num2;
        }
    }
};