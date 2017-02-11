class Solution {
public:
    bool test(const string& str, int step) {
        int n = str.size();
        for (int i = 0; i < step; ++i) {
            int j = i;
            while (j < n) {
                if (str[j] != str[i])
                    return false;
                j += step;
            }
        }
        return true;
    }

    bool repeatedSubstringPattern(string str) {
        int n = str.size();
        map<char, int> counter;
        for (int i = 0; i < n; ++i)
            counter[str[i]]++;
        if (counter.size() == 1)
            return n >= 2;
        vector<int> times;
        for (auto it = counter.begin(); it != counter.end(); ++it)
            times.push_back(it->second);
        sort(times.begin(), times.end());
        if (times[0] == 1)
            return false;
        int minCount = times[0];
        for (int i = 1; i < minCount; ++i) {
            if (minCount % i != 0)
                continue;
            int group = minCount / i;
            if (n % group != 0)
                continue;
            int step = n / group;
            if (test(str, step))
                return true;
        }
        return false;
    }
};