class Solution {
private:
    bool isValid(vector<int>& cnt) {
        return cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0;
    }

public:
    int numberOfSubstrings(string s) {
        vector<int> cnt(3, 0);
        int n = s.size(), i = 0, j = 0, ans = 0;
        while (j < n) {
            int k = s[j++] - 'a';
            cnt[k]++;
            while (isValid(cnt)) {
                k = s[i++] - 'a';
                cnt[k]--;
            }
            ans += i;
        }
        return ans;
    }
};
