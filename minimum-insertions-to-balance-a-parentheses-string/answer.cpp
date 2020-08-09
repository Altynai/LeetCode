class Solution {
public:
    int minInsertions(string a) {
        int n = a.size();
        int ans = 0;
        int l = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == '(') {
                l++;
            } else {
                if (i + 1 < n && a[i + 1] == ')') {
                    if (l == 0)
                        ans++;
                    else
                        l--;
                    i++;
                }
                else if (l == 0) {
                    ans += 2;
                } else {
                    l--;
                    ans++;
                }
            }
        }
        return ans + l * 2;
    }
};
