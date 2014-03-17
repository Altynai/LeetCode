
class Solution {
public:
    int jump(int A[], int n) {
        if (n <= 1)
            return 0;
        int curr_farest = 0, last_farest = 0, step = 0;
        for (int i = 0; curr_farest < n - 1; i++) {
            if (i + A[i] > curr_farest) {
                if (i > last_farest) {
                    last_farest = curr_farest;
                    step++;
                }
                curr_farest = i + A[i];
            }
        }
        return step + 1;
    }
};