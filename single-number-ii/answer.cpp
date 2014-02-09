
class Solution {
public:
    int singleNumber(int A[], int n) {
        int result = 0, bit_count = 0;
        for (int i = 0; i < 32; i++) {
            bit_count = 0;
            for (int j = 0; j < n; j++) {
                if (A[j] & (1 << i))
                    bit_count++;
            }
            bit_count %= 3;
            if (bit_count != 0)
                result += 1 << i;
        }
        return result;
    }
};
