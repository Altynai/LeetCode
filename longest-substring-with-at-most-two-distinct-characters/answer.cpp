class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.size();
        if (n <= 1)
            return n;
        int counter[256] = {0}, i = 0, j = 0, kinds = 0;
        int ans = 0, offset;
        while (true) {
            while (kinds > 2 && i < j) {
                offset = (int)s[i];
                counter[offset]--;
                if (counter[offset] == 0)
                    kinds--;
                i++;
            }
            ans = max(j - i, ans);
            if (j == n)
                break;
            offset = (int)s[j];
            counter[offset]++;
            if (counter[offset] == 1)
                kinds++;
            j++;
        }
        return ans;
    }
};