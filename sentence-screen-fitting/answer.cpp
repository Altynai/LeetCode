class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int ans = 0, index = 0, n = sentence.size();
        int total = 0;
        for (int i = 0; i < n; ++i)
            total += sentence[i].size();
        for (int i = 0; i < rows; ++i) {
            // loop * (total + n - 1) + loop - 1
            // loop * (total + n) - 1
            int loop = (cols + 1) / (total + n);
            int length = 0;
            if (loop > 0) {
                ans += loop;
                length = loop * (total + n) - 1;
            }
            while (1) {
                if (length == 0) {
                    if (sentence[index].size() <= cols)
                        length += sentence[index].size();
                    else
                        break;
                } else {
                    if (length + 1 + sentence[index].size() <= cols)
                        length += sentence[index].size() + 1;
                    else
                        break;
                }
                index++;
                if (index == n) {
                    ans++;
                    index = 0;
                }
            }
        }
        return ans;
    }
};