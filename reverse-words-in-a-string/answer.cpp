
class Solution {
public:
    void reverseWords(string &s) {
        int len = s.size(), n = 0;
        char *ch = new char[len];
        int high = len - 1, low = len;
        int index = 0;
        while (high >= 0) {
            if (s[high] == ' ')
                high--;
            else {
                low = high;
                while (low >= 0 && s[low] != ' ')
                    low--;
                if (index++)
                    ch[n++] = ' ';
                for (int i = low + 1; i <= high; i++)
                    ch[n++] = s[i];
                high = low;
            }
        }
        s = string(ch, ch + n);
    }
};