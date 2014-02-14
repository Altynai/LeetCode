
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int *val = new int[rowIndex + 1];
        int *temp = new int[rowIndex + 1];
        val[0] = 1;
        for (int i = 0; i < rowIndex; i++) {
            memcpy(temp, val, sizeof(int) * (i + 1));
            for (int j = 1; j <= i; j++)
                val[j] = temp[j] + temp[j - 1];
            val[i + 1] = 1;
        }
        return vector<int>(val, val + rowIndex + 1);
    }
};