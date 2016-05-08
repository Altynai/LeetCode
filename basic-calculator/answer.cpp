class Solution {
private:
    stack<string> stk;

    void calculateTopExpress() {
        if (stk.size() == 1)
            return;
        string value = stk.top();
        stk.pop();
        if (stk.top() == "(") {
            stk.push(value);
        } else {
            string express = stk.top();
            stk.pop();
            string base = stk.top();
            stk.pop();
            int answer = express == "+" ? std::stoi(base) + std::stoi(value) : \
                         std::stoi(base) - std::stoi(value);
            stk.push(std::to_string(answer));
            calculateTopExpress();
        }
    }

    void cleanTopParenthes() {
        string value = stk.top();
        stk.pop(); // value
        stk.pop(); // (
        stk.push(value);
        calculateTopExpress();
    }

public:
    int calculate(string s) {
        stk = stack<string>();
        int n = s.length(), i = 0;
        while (i < n) {
            if (s[i] == '(') {
                stk.push("(");
            } else if (s[i] == ')') {
                cleanTopParenthes();
            } else if (s[i] == '+') {
                stk.push("+");
            } else if (s[i] == '-') {
                stk.push("-");
            } else if (std::isdigit(s[i])) {
                string value = "";
                while (i < n && (s[i] == ' ' || std::isdigit(s[i]))) {
                    if (std::isdigit(s[i]))
                        value += s[i];
                    i++;
                }
                i--;
                stk.push(value);
                calculateTopExpress();
            }
            i++;
        }
        calculateTopExpress();
        return std::stoi(stk.top());
    }
};