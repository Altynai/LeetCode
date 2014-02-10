
class Solution {
public:
    int sqrt(int x) {
        if ( x <= 1)
            return x;
        double y = x >> 1;
        for (int i = 0; i < 31; i++)
            y = (y + x / y) * 0.5;
        return (int)y;
    }
};
