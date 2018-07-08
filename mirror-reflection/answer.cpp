class Solution {
public:
    int gcd(int a, int b) {
        if (a < b) swap(a, b);
        while (b != 0) {
            int c = a % b;
            a = b;
            b = c;
        }
        return a;
    }

    int lcm(int a, int b) {
        return a / gcd(a, b) * b;
    }

    int mirrorReflection(int p, int q) {
        if (q == 0)
            return 0;
        int ans = lcm(p * q, p * p);
        int x = ans / p / q, y = ans / p / p;
        if (x % 2 == 1 && y % 2 == 1)
            return 1;
        else if (x % 2 == 1 && y % 2 == 0)
            return 0;
        return 2;
    }
};
