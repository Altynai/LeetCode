#define int64 long long
const int64 mod = 1000000000 + 7;

class Solution {
private:
    int gcd(int a, int b) {
        while (b != 0) {
            int c = a % b;
            a = b;
            b = c;
        }
        return a;
    }
    
public:
    int nthMagicalNumber(int N, int A, int B) {
        if (A < B) swap(A, B);
        int lcm = A / gcd(A, B) * B;
        int64 low = 1, high = 1LL << 62, ans = 1;
        while (low <= high) {
            int64 mid = (low + high) >> 1;
            int64 cnt = mid / A - mid / lcm + mid / B;
            if (cnt >= N) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans % mod;
    }
};
