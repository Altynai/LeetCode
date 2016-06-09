
#define N 10

string dict0_9[N] = {
    "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven",
    "Eight", "Nine",
};

string dict10_19[N] = {
    "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
    "Sixteen", "Seventeen", "Eighteen", "Nineteen",
};

string dict20_90[N] = {
    "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy",
    "Eighty", "Ninety", "", "",
};

class Solution {
private:
    string combine(vector<string>& words) {
        std::stringstream ss;
        int n = words.size();
        for (int i = n - 1; i >= 0; --i) {
            if (i != n - 1 && words[i] != "")
                ss << " ";
            ss << words[i];
        }
        return ss.str();
    }

public:
    string numberToWords(int num) {
        if (num == 0)
            return dict0_9[0];
        vector<string> words;
        string units[4] = {"", "Thousand", "Million", "Billion"};
        for (int i = 0; num != 0 && i < 4; ++i) {
            int value = num % 1000;
            int hundred = value / 100;
            value %= 100;
            if (value == 0) {
                if (hundred > 0)
                    words.push_back(units[i]);
            }
            else if (value > 0 && value < 10) {
                words.push_back(units[i]);
                words.push_back(dict0_9[value]);
            } else if (value >= 10 && value < 20) {
                words.push_back(units[i]);
                words.push_back(dict10_19[value - 10]);
            } else { // 20 ~ 99
                words.push_back(units[i]);
                if (value % 10 == 0)
                    words.push_back(dict20_90[value / 10 - 2]);
                else {
                    words.push_back(dict0_9[value % 10]);
                    words.push_back(dict20_90[value / 10 - 2]);
                }
            }
            if (hundred > 0) {
                words.push_back("Hundred");
                words.push_back(dict0_9[hundred]);
            }
            num /= 1000;
        }
        return combine(words);
    }
};