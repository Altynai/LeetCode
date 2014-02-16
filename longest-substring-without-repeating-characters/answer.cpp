
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low = 0, high = 0;
        int length = s.size(), result = 0;
        int count[26] = {0}, index = 0;

        while (high < length) {
            while (high < length) {
                index = s[high] - 'a';
                if (count[index] >= 1)
                    break;
                else
                    count[index] += 1;
                high++;
            }
            result = std::max(result, high - low);
            while (high < length && low < high) {
                count[s[low] - 'a'] -= 1;
                low++;
                if (s[low - 1] - 'a' == index)
                    break;
            }
        }
        return result;
    }
};