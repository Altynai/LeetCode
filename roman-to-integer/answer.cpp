
class Solution {
private:
    int getOneCharIntValue(char ch) {
        if (ch == 'I')
            return 1;
        if (ch == 'V')
            return 5;
        if (ch == 'X')
            return 10;
        if (ch == 'L')
            return 50;
        if (ch == 'C')
            return 100;
        if (ch == 'D')
            return 500;
        if (ch == 'M')
            return 1000;
    }

public:
    int romanToInt(string s) {
        int result = 0, n = s.size();
        for (int i = 0; i < n;) {
            int current = getOneCharIntValue(s[i]);
            int next = 0;
            if (i + 1 < n) {
                next = getOneCharIntValue(s[i + 1]);
                if (next > current) {
                    result += next - current;
                    i += 2;
                    continue;
                }
            }
            // default
            result += current;
            i++;
        }
        return result;
    }
};