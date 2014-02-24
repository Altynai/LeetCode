
class Solution {
public:
    void sortColors(int A[], int n) {
        int count[3] = {0};
        for (int i = 0; i < n; i++)
            count[A[i]] += 1;
        int index = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < count[i]; j++)
                A[index++] = i;
        }
    }
};