class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0, n = bits.size();
        while (i < n - 1)
            i += bits[i] == 1 ? 2 : 1;
        return i == n - 1 && bits[i] == 0;
    }
};
