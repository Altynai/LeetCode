class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k <= 0)
            return 0;
        int counter[256] = {0};
        int types = 0, front = 0;
        int offset = 0, ans = 0;
        for (int end = 0; end < s.size(); ++end) {
            offset = (int)s[end];
            counter[offset]++;
            if (counter[offset] == 1)
                types++;
            while (types > k && front < end) {
                offset = (int)s[front++];
                counter[offset]--;
                if (counter[offset] == 0)
                    types--;
            }
            ans = max(ans, end - front + 1);
        }
        return ans;
    }
};