#include <iostream>
#include <vector>

using namespace std;

#define BI pair<bool, int>

class Solution {
public:
    int maxProduct(int A[], int n) {
        return maxRangeProduct(A, 0, n - 1).second;
    }

private:
    BI rangeProduct(int A[], int low, int high) {
        int p = 1;
        for (int i = low; i <= high; i++)
            p *= A[i];
        return newBI(true, p);
    }

    BI maxRangeProduct(int A[], int low, int high) {
        BI max_product = rangeProduct(A, low, high);
        if (max_product.second > 0)
            return max_product;

        vector<int> zeros;
        for (int i = low; i <= high; i++) {
            if (A[i] == 0)
                zeros.push_back(i);
        }

        max_product = newBI();
        int zero_num = zeros.size();
        if (zero_num > 0) {
            // tricky
            updateProduct(max_product, newBI(true, 0));
            // head
            if (zeros[0] > low)
                updateProduct(max_product, maxRangeProduct(A, low, zeros[0] - 1));
            // loop
            for (int i = 1; i < zero_num; i++) {
                if (zeros[i - 1] + 1 == zeros[i])
                    continue;
                updateProduct(max_product, maxRangeProduct(A, zeros[i - 1] + 1, zeros[i] - 1));
            }
            // tail
            if (zeros[zero_num - 1] < high)
                updateProduct(max_product, maxRangeProduct(A, zeros[zero_num - 1] + 1, high));
        } else {
            for (int i = low; i <= high; i++) {
                // tricky
                updateProduct(max_product, newBI(true, A[i]));
                if (A[i] > 0)
                    continue;
                if (i > low)
                    updateProduct(max_product, rangeProduct(A, low, i - 1));
                if (i < high)
                    updateProduct(max_product, rangeProduct(A, i + 1, high));
            }
        }
        // printf("#[%d, %d] %d\n", low, high, max_product.second);
        return max_product;
    }

    void updateProduct(BI &max_product, const BI &now_product) {
        if (!max_product.first || max_product.second < now_product.second) {
            max_product.first = true;
            max_product.second = now_product.second;
        }
    }

    BI newBI(const bool &_b = false, const int &_i = 0) {
        return make_pair(_b, _i);
    }
};

int main(int argc, char *argv[]) {
    int A[] = { -2, 3, 0, 2, -2, 3};
    int n = sizeof(A) / sizeof(int);
    Solution *solution = new Solution;
    printf("%d\n", solution->maxProduct(A, n));
}
