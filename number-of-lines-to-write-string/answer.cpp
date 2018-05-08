class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int count = S.size() > 0 ? 1 : 0, line = 0;
        for (char ch : S) {
            int width = widths[ch - 'a'];
            if (width <= 100 - line)
                line += width;
            else {
                line = width;
                count++;
            }
        }
        return vector<int>{count, line};
    }
};
