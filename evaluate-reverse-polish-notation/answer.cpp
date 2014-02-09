
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> rpn;
        int a = 0, b = 0, val = 0;

        for (int i = 0; i < tokens.size(); i++) {
            if (isInteger(tokens[i]))
                rpn.push(parseInteger(tokens[i]));
            else {
                b = rpn.top(); rpn.pop();
                a = rpn.top(); rpn.pop();
                val = calculate(a, b, tokens[i]);
                rpn.push(val);
            }
        }
        return rpn.top();
    }

private:
    bool isInteger(const string &s) {
        return s != "+" && s != "-" && s != "*" && s != "/";
    }

    int parseInteger(const string &s) {
        if (s[0] == '-')
            return -parseInteger(s.substr(1));
        int val = 0;
        for (int i = 0; i < s.size(); i++)
            val = val * 10 + (s[i] - '0');
        return val;
    }

    int calculate(const int &a, const int &b, const string &op) {
        if (op == "+")
            return a + b;
        else if (op == "-")
            return a - b;
        else if (op == "*")
            return a * b;
        else
            return a / b;
    }
};
