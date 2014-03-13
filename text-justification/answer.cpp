
class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        if (L == 0)
            return words;
        vector<string> result;
        int n = words.size();
        int low = 0, high = 0, length = 0, count = 0;
        while (high < n) {
            length = 0, count = 0;
            while (high < n && length + words[high].size() + count <= L) {
                length += words[high].size();
                high++;
                count++;
            }
            count--;
            int space = L - length; // at least one space between words
            string line = words[low];
            int number = (count ? space / count : space);
            int times = (count ? space % count : 0);
            // For the last line of text, it should be left
            // justified and no extra space is inserted between words.
            if (high == n) {
                number = 1;
                times = 0;
            }
            for (int i = low + 1; i < high; i++) {
                if (times) {
                    line += string(number + 1, ' ');
                    space -= number + 1;
                    times--;
                } else {
                    line += string(number, ' ');
                    space -= number;
                }
                line += words[i];
            }
            if (space)
                line += string(space, ' ');
            result.push_back(line);
            low = high;
        }
        return result;
    }
};
