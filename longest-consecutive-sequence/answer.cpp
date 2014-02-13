
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        vector<int> positive, nagtive;
        for (int i = 0; i < num.size(); i++) {
            if (num[i] >= 0)
                positive.push_back(num[i]);
            else
                nagtive.push_back(-num[i]);
        }
        positive = sort(positive);
        nagtive = sort(nagtive);
        for (int i = 0; i < nagtive.size(); i++)
            nagtive[i] = -nagtive[i];
        positive.insert(positive.begin(), nagtive.rbegin(), nagtive.rend());

        int longest = 1, current = 1;
        for (int i = 1; i < positive.size(); i++) {
            if (positive[i] == positive[i - 1])
                continue;
           	else if(positive[i] == positive[i - 1] + 1)
           		current++;
            else {
                longest = std::max(longest, current);
                current = 1;
            }
        }
        return std::max(longest, current);
    }

    vector<int> sort(vector<int> &num) {
        int max_length = findMaxLengthOfNumber(num);
        for (int i = 0; i < max_length; i++)
            num = radixSort(num, i);
        return num;
    }

    vector<int> radixSort(vector<int> &num, int p) {
        int radix[10] = {0}, count[10] = {0};
        for (int i = 0; i < num.size(); i++)
            count[digitAt(num[i], p)]++;
        for (int i = 1; i < 10; i++) {
            radix[i] = count[i - 1];
            count[i] += count[i - 1];
        }
        vector<int> result(num.begin(), num.end());
        for (int i = 0; i < num.size(); i++) {
            int digit = digitAt(num[i], p);
            result[radix[digit]++] = num[i];
        }
        return result;
    }

    int digitAt(int x, int p) {
        while (p--)
            x /= 10;
        return x % 10;
    }

    int findMaxLengthOfNumber(vector<int> &num) {
        int max_length = 0;
        for (int i = 0; i < num.size(); i++)
            max_length = std::max(lengthOfNumber(num[i]), max_length);
        return max_length;
    }

    int lengthOfNumber(int x) {
        int count = 0;
        while (x > 9) {
            count++;
            x /= 10;
        }
        return count + 1;
    }
};
