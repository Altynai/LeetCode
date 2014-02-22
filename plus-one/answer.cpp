
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int n = digits.size();
        digits[n - 1] += 1;
        n -= 1;
        while (n && digits[n] > 9) {
        	digits[n] %= 10;
        	digits[n - 1] += 1;
        	n -= 1;
        }
        if(digits[n] > 9){
        	digits[n] %= 10;
        	digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};