class Solution {
private:
    int gcd(int a, int b) {
        if (a < b)
            swap(a, b);
        while (b > 0) {
            int c = a % b;
            a = b;
            b = c;
        }
        return a;
    }

public:
    bool canMeasureWater(int x, int y, int z) {
        int c = gcd(x, y);
        if (c == 0)
            return z == 0;
        return x + y >= z && z % c == 0;
    }
};