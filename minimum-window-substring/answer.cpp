
class Solution {
private:
    static const int N = 256;

    void transferString(string &lh, string &rh) {
        if (lh == "" || rh.size() < lh.size())
            lh = rh;
        else if (lh.size() == rh.size() && rh < lh)
            lh = rh;
    }

public:
    string minWindow(string S, string T) {
        int s_len = S.size(), t_len = T.size();
        if (s_len == 0 || t_len == 0)
            return string("");
        int s_count[N] = {0}, t_count[N] = {0};
        for (int i = 0; i < t_len; i++)
            t_count[T[i]]++;
        int appear = accumulate(t_count, t_count + N, 0);
        int low = 0, high = 0, currnt_appear = 0, index = 0;
        string result = "";

        // init
        do {
            index = S[high];
            s_count[index]++;
            if (t_count[index] && s_count[index] <= t_count[index])
                currnt_appear++;
            while (currnt_appear == appear) {
                index = S[low];
                s_count[index]--;
                if (t_count[index] && s_count[index] < t_count[index]) {
                    currnt_appear--;
                    if (currnt_appear < appear) {
                        string temp = S.substr(low, high - low + 1);
                        transferString(result, temp);
                    }
                }
                low++;
            }
            high++;
        } while (high < s_len);
        return result;
    }
};