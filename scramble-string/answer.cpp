
class Solution {
private:
    static const int N = 26;
    int s1_len;
    int s2_len;
    int **s1_count;
    int **s2_count;

    void alloc(const string &s, int ** &count, int &len) {
        len = s.size();
        count = new int *[len];
        for (int i = 0; i < len; i++) {
            count[i] = new int[N];
            memset(count[i], 0, sizeof(int) * N);
        }
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < N; j++) {
                if (i)
                    count[i][j] = count[i - 1][j];
            }
            count[i][s[i] - 'a']++;
        }
    }

    void init(const string &s1, const string &s2) {
        alloc(s1, s1_count, s1_len);
        alloc(s2, s2_count, s2_len);
    }

    int countChar(int **count, int low, int high, int index) {
        if (low == 0)
            return count[high][index];
        else
            return count[high][index] - count[low - 1][index];
    }

    bool match(int s1_low, int s1_high, int s2_low, int s2_high) {
        if (s1_high < s1_low || s2_high < s2_low)
            return false;
        if (s1_high - s1_low != s2_high - s2_low)
            return false;
        for (int index = 0; index < N; index++) {
            int count_a = countChar(s1_count, s1_low, s1_high, index);
            int count_b = countChar(s2_count, s2_low, s2_high, index);
            if (count_a != count_b)
                return false;
        }
        return true;
    }

    bool dfs(int s1_low, int s1_high, int s2_low, int s2_high) {
        if (!match(s1_low, s1_high, s2_low, s2_high))
            return false;
        if (s1_low == s1_high || s2_low == s2_high)
            return match(s1_low, s1_high, s2_low, s2_high);

        for (int i = 0; i < s1_high - s1_low; i++) {
            if (dfs(s1_low, s1_low + i, s2_low, s2_low + i) && \
                    dfs(s1_low + i + 1, s1_high, s2_low + i + 1, s2_high)) {
                return true;
            }
        }
        for (int i = 0; i < s1_high - s1_low; i++) {
            if (dfs(s1_low, s1_low + i, s2_high - i, s2_high) && \
                    dfs(s1_low + i + 1, s1_high, s2_low, s2_high - i - 1)) {
                return true;
            }
        }
        // otherwise
        return false;
    }

public:
    bool isScramble(string s1, string s2) {
        init(s1, s2);
        return dfs(0, s1_len - 1, 0, s2_len - 1);
    }
};
