class Solution {
public:
    int brokenCalc(int X, int Y) {
        int ans = 0;
        while (Y > X) {
            ans++;
            Y = (Y % 2 == 0) ? Y / 2 : Y + 1;
        }
        return ans + X - Y;
    }
};
