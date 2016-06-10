class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2)
            return 0;
        vector<bool> is_prime(n, true);
        for (int i = 4; i < n; i += 2)
            is_prime[i] = false;
        is_prime[2] = true;
        int root = (int)sqrt((double)n);
        for (int i = 3; i <= root; i += 2) {
            if (is_prime[i]) {
                for (int j = i * i; j <= n; j += i)
                    is_prime[j] = false;
            }
        }
        int count = 1;
        for (int i = 3; i < n; i += 2)
            if (is_prime[i])
                count++;
        return count;
    }
};