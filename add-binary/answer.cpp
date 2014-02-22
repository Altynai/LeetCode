
class Solution {
private:
    char charAt(const string &s, int index) {
        if (index >= s.size())
            return '0';
        else
            return s[index];
    }

public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int n = std::max(a.size(), b.size());
        string result(n, '0');
        for (int i = 0; i < n; i++) {
            int sum = charAt(a, i) - '0' + charAt(b, i) - '0';
            result[i] += sum;
            if (result[i] >= '2') {
                result[i] -= 2;
                if (i == n - 1)
                    result.push_back('1');
                else
                    result[i + 1] += 1;
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};