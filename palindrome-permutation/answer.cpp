class Solution {
public:
    bool canPermutePalindrome(string s) {
        int n = s.size();
        if (n <= 1)
            return true;
        map<char, int> counter;
        for (int i = 0; i < n; ++i)
            counter[s[i]]++;
        int even = 0, odd = 0;
        for (auto it = counter.begin(); it != counter.end(); ++it)
            it->second % 2 == 0 ? even++ : odd++;
        if (n % 2 == 0)
            return odd == 0;
        return odd == 1;
    }
};