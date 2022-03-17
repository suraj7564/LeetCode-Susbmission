class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> stack;
        stack.push(0);

        for (char c : s) {

            if (c == '(')
                stack.push(0);

            else {

                int tmp = stack.top();
                stack.pop();

                int val = 0;

                if (tmp > 0)
                    val = tmp * 2;

                else
                    val = 1;

                stack.top() += val;
            }
        }
            return stack.top();
    }
};