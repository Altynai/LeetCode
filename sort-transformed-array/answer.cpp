class Solution {
public:
    vector<int> lineTransformedArray(vector<int>& nums, int b, int c) {
        int n = nums.size();
        vector<int> ans(n, c);
        for (int i = 0; i < nums.size(); ++i)
            ans[i] += (b >= 0) ? nums[i] * b : nums[n - 1 - i] * b;
        return ans;
    }

    vector<int> parabolaTransformedArray(vector<int>& nums, int a, int b, int c) {
        double symmetry = (double)(-b) / (a + a);
        int n = nums.size();
        vector<int> ans(n, 0);
        int i = -1, j = n;
        for (int k = 0; k < n && nums[k] <= symmetry; ++k)
            i = k;
        for (int k = n - 1; k >= 0 && (double)nums[k] > symmetry; --k)
            j = k;
        int index = (a > 0) ? 0 : n - 1;
        int step = (a > 0) ? 1 : -1;
        while (i != -1 || j != n) {
            bool usei = false;
            if (i == -1)
                usei = false;
            else if (j == n)
                usei = true;
            else {
                double di = symmetry - nums[i], dj = (double)nums[j] - symmetry;
                if (di <= dj)
                    usei = true;
                else
                    usei = false;
            }
            int value = 0;
            if (usei) {
                value = a * nums[i] * nums[i] + b * nums[i] + c;
                i--;
            } else {
                value = a * nums[j] * nums[j] + b * nums[j] + c;
                j++;
            }
            ans[index] = value;
            index += step;
        }
        return ans;
    }

    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        if (a == 0)
            return lineTransformedArray(nums, b, c);
        return parabolaTransformedArray(nums, a, b, c);
    }
};