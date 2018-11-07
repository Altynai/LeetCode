class Solution {
private:
    bool match(int p, string& s, string& t) {
        bool all = true;
        for (int i = 0; i < s.size(); i++) {
            if (t[p + i] == '?')
                continue;
            else if (s[i] != t[p + i])
                return false;
            all = false;
        }
        return !all;
    }

    int cover(int p, string& s, string& t) {
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (t[p + i] != '?') {
                cnt++;
                t[p + i] = '?';
            }
        }
        return cnt;
    }

public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> ans;
        int n = stamp.size(), m = target.size();
        int remain = m;

        while (remain > 0) {
            int cnt = -1;
            for (int i = 0; i <= m - n; i++) {
                if (match(i, stamp, target)) {
                    cnt = cover(i, stamp, target);
                    ans.push_back(i);
                    break;
                }
            }
            if (cnt <= 0)
                return {};
            remain -= cnt;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
