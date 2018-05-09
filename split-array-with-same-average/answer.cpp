
class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        int n = A.size();
        if (n <= 1)
            return false;
        int total = 0;
        for (int num : A)
            total += num;
        int m = n / 2;
        vector<set<int>> sums(m + 1);
        sums[0].insert(0);
        for (int num : A) {
            for (int i = m; i >= 1; i--) {
                for (int pre : sums[i - 1])
                    sums[i].insert(pre + num);
            }
        }
        for (int i = 1; i <= m; i++) {
            // sum / i == total / n
            if (total * i % n == 0 && sums[i].find(total * i / n) != sums[i].end())
                return true;
        }
        return false;
    }
};
