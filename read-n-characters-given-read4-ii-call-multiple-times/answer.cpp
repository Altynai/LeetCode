// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    int index;
    int count;
    char* systemBuf;
    bool isEmpty;

    Solution() {
        index = 0;
        count = 0;
        systemBuf = new char[4];
        isEmpty = false;
    }

    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        if (n == 0)
            return 0;
        int total = 0;
        while (n--) {
            if (isEmpty)
                return total;
            else if (index < count) {
                *buf = *(systemBuf + index);
                buf++;
                index++;
                total++;
            } else {
                index = 0;
                count = read4(systemBuf);
                if (count == 0)
                    isEmpty = true;
                else {
                    *buf = *(systemBuf + index);
                    buf++;
                    index++;
                    total++;
                }
            }
        }
        return total;
    }
};