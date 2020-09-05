class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& a) {
        int n = a.size();
        int l = 1;
        while (l < n && a[l] >= a[l - 1]) l++;
        if (l == n)
            return 0;

        int r = n - 2;
        while (r >= 0 && a[r] <= a[r + 1]) r--;

        int ans = max(l, n - r - 1);
        r++;
        for (int i = 0; i < l; i++) {
            while (r < n && a[r] < a[i]) r++;
            ans = max(ans, i + 1 + n - r);
        }
        return n - ans;
    }
};
