class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x ^ y, count = 0;
        for (int i = 0; i < 32; i++, z >>= 1)
            z & 1 ? count += 1 : count += 0;
        return count;
    }
};