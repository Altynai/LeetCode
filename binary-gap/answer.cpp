class Solution {
public:
    int binaryGap(int N) {
        vector<int> bits;
        while (N > 0) {
            bits.push_back(N % 2);
            N /= 2;
        }
        reverse(bits.begin(), bits.end());
        int gap = 0, pre = -1, n = bits.size();
        for (int i = 0; i < n; i++) {
            if (bits[i] == 0)
                continue;
            if (pre != -1)
                gap = max(gap, i - pre);
            pre = i;
        }
        return gap;
    }
};
