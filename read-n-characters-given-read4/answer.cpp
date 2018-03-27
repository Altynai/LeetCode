// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        // read n / 4 times
        int count = 0;
        char tmp[4];
        for (int i = 0; i < n / 4; i++) {
            int m = read4(tmp);
            for (int j = 0; j < m; j++) {
                *buf = tmp[j];
                buf++;
            }
            count += m;
            if (m < 4)
                return count;
        }
        // read left n % 4
        if (n % 4 > 0) {
            int m = read4(tmp);
            for (int j = 0; j < min(m, n % 4); j++) {
                *buf = tmp[j];
                buf++;
                count++;
            }
        }
        return count;
    }
};