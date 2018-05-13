class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int n = data.size(), i = 0;
        while (i < n) {
            // 4 bytes
            if (data[i] >> 3 == (1 << 5) - 2) {
                i++;
                for (int j = 0; j < 3; j++) {
                    if (i >= n)
                        return false;
                    if (data[i] >> 6 != 2)
                        return false;
                    i++;
                }
            } else if (data[i] >> 4 == (1 << 4) - 2) { // 3 bytes
                i++;
                for (int j = 0; j < 2; j++) {
                    if (i >= n)
                        return false;
                    if (data[i] >> 6 != 2)
                        return false;
                    i++;
                }
            } else if (data[i] >> 5 == (1 << 3) - 2) { // 2 bytes
                i++;
                if (i >= n)
                    return false;
                if (data[i] >> 6 != 2)
                    return false;
                    i++;
            } else if (data[i] >> 7 == 0)
                i++;
            else
                return false;
        }
        return true;
    }
};
