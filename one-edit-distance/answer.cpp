class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int ns = s.size(), nt = t.size();
        if (abs(ns - nt) > 1) {
            return false;
        }
        if (ns == nt) {
            int diff = 0;
            for (int i = 0; i < ns; i++) {
                if (s[i] != t[i])
                    diff++;
                if (diff > 1)
                    return false;
            }
            return diff == 1;
        }
        // s: shorter string
        // t: longer string
        if (ns > nt) {
            swap(s, t);
            ns = s.size(), nt = t.size();
        }
        bool used = false;
        for (int i = 0, j = 0; i < ns; i++, j++) {
            if (s[i] != t[j]) {
                if (used)
                    return false;
                used = true;
                i--;
            }
        }
        return true;
    }
};