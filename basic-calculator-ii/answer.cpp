#include <cassert>
#include <string>
#include <fstream>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        if (n == 0)
            return 0;
        int i = 0, sign = 1, previous = 0, answer = 0;
        while (i < n) {
            if (s[i] == ' ') {
                i++;
                continue;
            } else if (isdigit(s[i])) {
                int number = 0;
                while (i < n && (s[i] == ' ' || isdigit(s[i]))) {
                    if (isdigit(s[i]))
                        number = number * 10 + (s[i] - '0');
                    i++;
                }
                number = sign * number;
                previous += number;
            } else {
                char symbol = s[i];
                i++;
                if (symbol == '+' || symbol == '-') {
                    sign = symbol == '+' ? 1 : -1;
                    answer += previous;
                    previous = 0;
                } else {
                    int number = 0;
                    while (i < n && (s[i] == ' ' || isdigit(s[i]))) {
                        if (isdigit(s[i]))
                            number = number * 10 + (s[i] - '0');
                        i++;
                    }
                    if (symbol == '*')
                        previous = previous * number;
                    else
                        previous = (int)(previous / number);
                }
            }
        }
        answer += previous;
        return answer;
    }
};

int main(int argc, char const *argv[]) {
    Solution *s = new Solution();
    assert(s->calculate("3+2*2") == 7);
    assert(s->calculate("0") == 0);
    assert(s->calculate(" 3/2 ") == 1);
    assert(s->calculate(" 3+5 / 2 ") == 5);
    assert(s->calculate("8+5-1+9/3+5*6/3") == 25);
    // test long expression
    ifstream infile("longExpression.txt");
    string expression;
    infile >> expression;
    assert(s->calculate(expression) == 199);
    return 0;
}