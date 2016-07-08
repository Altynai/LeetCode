class Solution {
private:
    string num;

    string addTwoStrings(const string& lh, const string& rh) {
        int n = lh.size(), m = rh.size();
        char* ans = new char[max(n, m) + 2];
        int carry = 0, pos = 0;
        for (int i = n - 1, j = m - 1; i >= 0 || j >= 0; i--, j--) {
            int a = (i < 0) ? 0 : lh[i] - '0';
            int b = (j < 0) ? 0 : rh[j] - '0';
            int c = a + b + carry;
            ans[pos++] = c % 10 + '0';
            carry = c > 9 ? 1 : 0;
        }
        if (carry == 1)
            ans[pos++] = '1';
        ans[pos] = '\0';
        reverse(ans, ans + pos);
        return string(ans);
    }

    bool isAdditive(string& lh, string &rh, int starts) {
        // basic check
        if (lh.size() == 0 || rh.size() == 0)
            return false;
        if ((lh.size() > 1 && lh[0] == '0') || (rh.size() > 1 && rh[0] == '0'))
            return false;
        bool first = bool(starts == lh.size() + rh.size());
        if (starts == num.size())
            return !first;
        string added = addTwoStrings(lh, rh);
        if (num.size() - added.size() < starts)
            return false;
        string cut = num.substr(starts, added.size());
        if (cut != added)
            return false;
        return isAdditive(rh, added, starts + added.size());
    }

public:
    bool isAdditiveNumber(string num) {
        this->num = num;
        int n = num.size();
        if (n <= 2)
            return false;
        for (int i = 1; i <= n / 2; ++i) {
            string lh = num.substr(0, i);
            for (int j = 1; i + j + max(i, j) <= n; ++j) {
                string rh = num.substr(i, j);
                if (isAdditive(lh, rh, i + j))
                    return true;
            }
        }
        return false;
    }
};