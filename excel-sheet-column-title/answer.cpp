class Solution {
public:
    string convertToTitle(int n) {
        string result = "";
        do {
            n--;
            result.insert(result.begin(), (char)('A' + n % 26));
            n /= 26;
        } while (n >= 1);
        return result;
    }
};